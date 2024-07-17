#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class From {
    private:
        const std::string   name;
        bool                isSigned;
        const unsigned int  signGrade;
        const unsigned int  execGrade;
    public:
        From();
        Form(const std::string name, const unsigned int signGrade, const unsigned int execGrade);
        Form(const Form &src);
        ~Form();

        Form &operator =(const Form &src);

        void            getName() const;
        bool            isFormSigned() const;
        unsigned int    getSignGrade() const;
        unsigned int    getExecGrade() const;

        void    beSigned(const Bureaucrat &b);
        
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