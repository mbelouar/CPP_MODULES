#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
        std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!this->isFormSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << ">> Drilling noises..." << std::endl;
    bool success = std::rand() % 2; // Randomly choose between 0 and 1
    if (success)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
