# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat() : name("None"), grade(LOW_GRADE) {
    std::cout << "Bureaucrat Default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name){
    if (grade < HIGHT_GRADE) {
        throw GradeTooHighException();
    } else if (grade > LOW_GRADE) {
        throw GradeTooLowException();
    }
    this->grade = grade;
    std::cout << "Bureaucrat Parametric constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName() + "_copy") {
    std::cout << "Bureaucrat Copy constructor." << std::endl;
    *this = src;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor." << std::endl;
}

Bureaucrat &Bureaucrat::operator =(const Bureaucrat &src) {
    if (this != &src) {
        std::cout << "Bureaucrat copy assignment operator." << std::endl;
        this->grade = src.getGrade();
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return this->name;
}

unsigned int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::IncGrade() {
    if (grade <= HIGHT_GRADE) {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::DecGrade() {
    if (grade >= LOW_GRADE) {
        throw GradeTooLowException();
    }
    grade++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b) {
    output << b.getName() << ", bureaucrat grade " << b.getGrade();
    return output;
}
