#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("John", 2);
        std::cout << b1 << std::endl;
        b1.IncGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2("Doe", 148);
        std::cout << b2 << std::endl;
        b2.DecGrade();
        std::cout << b2 << std::endl;

        Bureaucrat b3(b2);
        std::cout << b3 << std::endl;
        b3.DecGrade();
        std::cout << b3 << std::endl;

        Bureaucrat b4(b1);
        std::cout << b4 << std::endl;
        b4.IncGrade();
        // An exception must be thrown here
        std::cout << b4 << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    try {
        // This should also throw an exception
        std::cout << ">> ";
        Bureaucrat b4("Invalid", 151);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    try {
        Bureaucrat b5("Test", 1);
        b5.IncGrade(); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    try {
        Bureaucrat b6("Test", 150);
        b6.DecGrade(); // This should throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    return 0;
}
