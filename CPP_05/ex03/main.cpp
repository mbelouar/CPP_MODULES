#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b1("John", 1);
            b1.signForm(*rrf);
            b1.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        rrf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b2("Alice", 1);
            b2.signForm(*rrf);
            b2.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (rrf) {
            std::cout << *rrf << std::endl;
            Bureaucrat b3("Doe", 1);
            b3.signForm(*rrf);
            b3.executeForm(*rrf);
            delete rrf;
        }
        std::cout << "----------------------------------------" << std::endl;

        // This should throw an exception
        rrf = someRandomIntern.makeForm("unknown", "Nobody");
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
