#include <iostream>

template <typename T>
class Animal {
public:
    void make_sound() const {
        static_cast<const T*>(this)->make_sound_impl();
        //static_cast<const T&>(*this).make_sound_impl();
    }
};

class Dog : public Animal<Dog> {
public:
    void make_sound_impl() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal<Cat> {
public:
    void make_sound_impl() const {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    dog.make_sound();  // Prints "Woof!"
    cat.make_sound();  // Prints "Meow!"
    return 0;
}

/*
Perchè qua non mi da errore su make_sound_impl() anche se non l'ho ancora neanche dichiarato?

Il motivo per cui non ottieni un errore di compilazione è dovuto al fatto che il metodo make_sound_impl() 
non viene effettivamente chiamato nel template della classe Animal. Invece, viene chiamato su un oggetto 
di tipo T, che è il tipo derivato.

Quando scrivi static_cast<const T*>(this)->make_sound_impl(), stai dicendo al compilatore di trattare 
this come se fosse un puntatore a T e poi di chiamare make_sound_impl() su di esso. A questo punto, 
il compilatore non ha bisogno di sapere se T ha un metodo make_sound_impl() o no, perché non sta 
effettivamente generando codice per chiamare make_sound_impl(). Il codice per chiamare make_sound_impl() 
verrà generato solo quando il template Animal sarà specializzato per un tipo specifico T che ha un metodo 
make_sound_impl().

Questo è un aspetto chiave del Curiously Recurring Template Pattern (CRTP). Il template della classe 
base (in questo caso Animal) chiama metodi sulla classe derivata (in questo caso T), e questi metodi 
devono essere definiti nella classe derivata. Se provi a specializzare Animal per un tipo che non ha 
un metodo make_sound_impl(), allora otterrai un errore di compilazione.
*/