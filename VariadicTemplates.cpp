#include <iostream>

template<class T>
T sum(T t) {
    return t;
}

template<class T, class... Args>
T sum(T t, Args... args) {
    return t + sum(args...);
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;  // Prints 15
    return 0;
}