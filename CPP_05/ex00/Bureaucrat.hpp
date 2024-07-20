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
                    std::cout << "Exception : ";
                    return "Grade is too high! the maximum grade is 1";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    std::cout << "Exception : ";
                    return "Grade is too low! the maximum grade is 150";
                }
        };
};

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &b);

#endif