#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern randomIntern;
        AForm* rrf;
        
        rrf = randomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b1("Simo", 1);
            b1.signForm(*rrf);
            b1.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        rrf = randomIntern.makeForm("shrubbery creation", "home");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b2("Bickle", 1);
            b2.signForm(*rrf);
            b2.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        rrf = randomIntern.makeForm("presidential pardon", "Ford");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b3("Bello", 1);
            b3.signForm(*rrf);
            b3.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        // This should throw an exception
        rrf = randomIntern.makeForm("unknown", "Nobody");
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
