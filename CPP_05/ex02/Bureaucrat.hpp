#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

# define HIGHT_GRADE 1
# define LOW_GRADE 150

class AForm;

class Bureaucrat {
    private:
        const std::string   name;
        unsigned int        grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat  &operator =(const Bureaucrat &src);
        ~Bureaucrat();

        std::string     getName() const;
        unsigned int    getGrade() const;
        void            IncGrade();
        void            DecGrade();

        void signForm(AForm form) const;
        void executeForm(AForm const &form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &b);

#endif