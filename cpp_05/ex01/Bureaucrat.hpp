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
        Bureaucrat(const std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat  &operator =(const Bureaucrat &src);

        std::string getName() const;
        unsigned int getGrade() const;
        void Bureaucrat::IncGrade();
        void Bureaucrat::DecGrade();
};


#endif