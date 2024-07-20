#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
};

#endif
