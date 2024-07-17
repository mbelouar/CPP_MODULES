#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

# define HIGHT_GRADE 1
# define LOW_GRADE 150

class Bureaucrat {
    private:
        const std::string   name;
        unsigned int        grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();

        Bureaucrat  &operator =(const Bureaucrat &src);

        std::string     getName() const;
        unsigned int    getGrade() const;
        void            IncGrade();
        void            DecGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Grade is too low!";
                }
        };
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &b);

#endif