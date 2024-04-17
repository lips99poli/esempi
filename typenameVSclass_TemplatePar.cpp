// Differenza tra class e typename in template parameters

#include <iostream>

// Define a struct with a nested type
struct MyStruct {
    typedef int NestedType;
};

// Define a template function foo using 'class'
template <class T>
void foo() {
    T t;
    std::cout << "In foo(), T is of size: " << sizeof(t) << std::endl;
}

// Define a template function bar using 'typename'
template <class T>
void bar() {
    typename T::NestedType x;
    std::cout << "In bar(), T::NestedType is of size: " << sizeof(x) << std::endl;
}

int main() {
    foo<MyStruct>();
    bar<MyStruct>();
    return 0;
}