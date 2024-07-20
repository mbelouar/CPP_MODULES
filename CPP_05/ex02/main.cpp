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

        Bureaucrat b2("Doe", 1);
        RobotomyRequestForm f2("robot");
        std::cout << f2 << std::endl;
        b2.signForm(f2);
        b2.executeForm(f2);

        Bureaucrat b3("Alice", 1);
        PresidentialPardonForm f3("Alice");
        std::cout << f3 << std::endl;
        b3.signForm(f3);
        b3.executeForm(f3);

        // This should throw an exception
        ShrubberyCreationForm f4("office");
        Bureaucrat b4("Bob", 150);
        b4.signForm(f4);
        b4.executeForm(f4); // Should fail due to insufficient grade for execution

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
