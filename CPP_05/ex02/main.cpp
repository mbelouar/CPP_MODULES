#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat b1("John", 2);
        ShrubberyCreationForm f1("home");
        std::cout << f1 << std::endl;
        b1.signForm(f1);
        b1.executeForm(f1);
        std::cout << "----------------------------------------" << std::endl;

        Bureaucrat b2("Doe", 1);
        RobotomyRequestForm f2("ROBOT");
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        b2.executeForm(f2);
        std::cout << "----------------------------------------" << std::endl;

        Bureaucrat b3("Alice", 1);
        PresidentialPardonForm f3("ALICE");
        std::cout << f3 << std::endl;
        b3.signForm(f3);
        b3.executeForm(f3);
        std::cout << "----------------------------------------" << std::endl;

        // This should throw an exception
        Bureaucrat b4("Bob", 150);
        ShrubberyCreationForm f4("OFFICE");
        b4.signForm(f4);
        b4.executeForm(f4); // Should fail due to insufficient grade for execution
        std::cout << "----------------------------------------" << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
