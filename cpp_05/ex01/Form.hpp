#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string   name;
        bool                isSigned;
        const unsigned int  signGrade;
        const unsigned int  execGrade;
    public:
        Form();
        Form(std::string name, unsigned int signGrade, unsigned int execGrade);
        Form(const Form &src);
        ~Form();

        Form &operator =(const Form &src);

        std::string     getName() const;
        bool            isFormSigned() const;
        unsigned int    getSignGrade() const;
        unsigned int    getExecGrade() const;

        void    beSigned(const Bureaucrat b);
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Form Grade is too low!";
                }
        };

};

std::ostream	&operator<<(std::ostream &output, const Form &f);

#endif