# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("None"), grade(LOW_GRADE) {
    std::cout << "Bureaucrat Default constructor." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : name(name), grade(grade) {
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
    if (this->grade < HIGHT_GRADE) {
         // throw execption
    }
    this->grade--;
}

void Bureaucrat::DecGrade() {
    if (this->grade > LOW_GRADE) {
        // throw exception
    }
    this->grade++;
}