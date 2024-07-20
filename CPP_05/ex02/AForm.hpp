#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   name;
        bool                isSigned;
        const unsigned int  signGrade;
        const unsigned int  execGrade;
    public:
        AForm();
        AForm(std::string name, unsigned int signGrade, unsigned int execGrade);
        AForm(const AForm &src);
        virtual ~AForm();

        AForm &operator =(const AForm &src);

        virtual void execute(Bureaucrat const &executor) const = 0;

        std::string     getName() const;
        bool            isFormSigned() const;
        unsigned int    getSignGrade() const;
        unsigned int    getExecGrade() const;

        void    beSigned(const Bureaucrat b);
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream	&operator<<(std::ostream &output, const AForm &f);

#endif