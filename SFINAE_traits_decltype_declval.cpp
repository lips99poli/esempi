#include <iostream>
#include <type_traits>

// Helper struct to check if a type has a size() method
template <typename T, typename = void>
struct has_size : std::false_type {};

template <typename T>
struct has_size<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

// Version of the template for types that have a size() method
template <typename T>
std::enable_if_t<has_size<T>::value> print_size(T t) {
    std::cout << t.size() << std::endl;
}

// Version of the template for types that do not have a size() method
template <typename T>
std::enable_if_t<!has_size<T>::value> print_size(T t) {
    std::cout << "Type does not have size()" << std::endl;
}

int main() {
    std::string s = "Hello";
    print_size("Hello");  // Prints 5
    print_size(s);
    print_size(42);       // Prints "Type does not have size()"
    return 0;
}