#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("John", 2);
        std::cout << b1 << std::endl;

        Form f1("Form1", 1, 50);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        std::cout << f1 << std::endl;

        Bureaucrat b2("Doe", 150);
        std::cout << b2 << std::endl;

        Form f2("Form2", 150, 150);
        std::cout << f2 << std::endl;

        b2.signForm(f2);
        std::cout << f2 << std::endl;

        // Test with invalid grade form
        Form f3("Form3", 0, 150);
    } 
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    try {
        // Test with invalid grade form
        Form f4("Form4", 151, 150);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    try {
        Bureaucrat b3("Test", 1);
        Form f5("Form5", 1, 50);
        std::cout << f5 << std::endl;
        b3.signForm(f5); // This should work
        std::cout << f5 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "===============================" << std::endl;

    return 0;
}
