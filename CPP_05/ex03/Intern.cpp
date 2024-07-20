#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    // std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
    // std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

Intern::~Intern() {
    // std::cout << "Intern destructor called" << std::endl;
}

Intern  &Intern::operator=(Intern const &src) {
    (void)src;
    //  std::cout << "Intern assignation operator called" << std::endl;
    return *this;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Exception: Form not found!";
}

AForm   *Intern::makeForm(std::string formName, std::string target) {
    if (formName == "shrubbery creation") {
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new ShrubberyCreationForm(target);
    } else if (formName == "robotomy request") {
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new RobotomyRequestForm(target);
    } else if (formName == "presidential pardon") {
        std::cout << "Intern creates " << formName << " form" << std::endl;
        return new PresidentialPardonForm(target);
    } else {
        throw Intern::FormNotFoundException();
    }
}