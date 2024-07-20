#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
# include <cstdlib>

class RobotomyRequestForm : public AForm {
private:
    std::string target;

public:
    RobotomyRequestForm(const std::string &target);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
};

#endif
