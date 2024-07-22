// #include "ScalarConversion.hpp"
#include <iostream>
#include <string>
int main() {

    int a;
    std::cout << "before : " << sizeof(a) << std::endl;
    double b = 20.5;
    a = b;
    std::cout << "a = " << a << std::endl;
    std::cout << "After : " << sizeof(a) << std::endl;
    return 0;
}