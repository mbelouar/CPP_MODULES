#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Intern {
    private:

    public:
        Intern();
        Intern(Intern const & src);
        ~Intern();

        Intern & operator=(Intern const &src);

        AForm * makeForm(std::string formName, std::string target);

        class FormNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif