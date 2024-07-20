#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm {
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string &target);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;
};

#endif
