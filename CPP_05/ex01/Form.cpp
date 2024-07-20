# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form()
	: name("None"), signGrade(HIGHT_GRADE), execGrade(HIGHT_GRADE)
{
	this->isSigned = false;
}

Form::Form(std::string name, unsigned int signGrade, unsigned int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < HIGHT_GRADE || execGrade < HIGHT_GRADE) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (signGrade > LOW_GRADE || execGrade > LOW_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Form::Form(const Form &src)
    : name(src.getName() + "_copy"), signGrade(src.getSignGrade()), execGrade(src.getExecGrade()) {
    *this = src;
}

Form    &Form::operator =(const Form &src) {
    if (this != &src) {
        this->isSigned = src.isFormSigned();
    }
    return *this;
}

Form::~Form() {
}

std::string Form::getName() const {
    return this->name;
}

bool Form::isFormSigned() const {
    return this->isSigned;
}

unsigned int Form::getSignGrade() const {
    return this->signGrade;
}

unsigned int Form::getExecGrade() const {
    return this->execGrade;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Exception: Form Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Exception: Form Grade is too low!";
}

void    Form::beSigned(const Bureaucrat bureau) {
    if (bureau.getGrade() > this->signGrade) {
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& output, const Form& form) {
    output << "Form " << form.getName() << ", Signed: " << (form.isFormSigned() ? "Yes" : "No")
           << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecGrade();
    return output;
}