#include <iostream>
template <typename T>
class MyClass {
public:
    static int count;
};

// Initialize static member for int specialization
template<> int MyClass<int>::count = 0;

// Initialize static member for double specialization
template<> int MyClass<double>::count = 0;

int main() {
    MyClass<int>::count++;
    MyClass<double>::count++;
    std::cout << MyClass<int>::count << std::endl;    // Prints 1
    std::cout << MyClass<double>::count << std::endl; // Prints 1
    return 0;
}