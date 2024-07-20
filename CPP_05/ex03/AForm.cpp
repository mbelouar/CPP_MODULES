# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm()
	: name("None"), signGrade(HIGHT_GRADE), execGrade(HIGHT_GRADE)
{
	this->isSigned = false;
}

AForm::AForm(std::string name, unsigned int signGrade, unsigned int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < HIGHT_GRADE || execGrade < HIGHT_GRADE) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (signGrade > LOW_GRADE || execGrade > LOW_GRADE) {
        throw Bureaucrat::GradeTooLowException();
    }
}

AForm::AForm(const AForm &src)
    : name(src.getName() + "_copy"), signGrade(src.getSignGrade()), execGrade(src.getExecGrade()) {
    *this = src;
}

AForm    &AForm::operator =(const AForm &src) {
    if (this != &src) {
        this->isSigned = src.isFormSigned();
    }
    return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::isFormSigned() const {
    return this->isSigned;
}

unsigned int AForm::getSignGrade() const {
    return this->signGrade;
}

unsigned int AForm::getExecGrade() const {
    return this->execGrade;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Exception: Form Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Exception: Form Grade is too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "Exception: Form is not signed!";
}

void    AForm::beSigned(const Bureaucrat bureau) {
    if (bureau.getGrade() > this->signGrade) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& output, const AForm& form) {
    output << "Form " << form.getName() << "\n\t|--> Signed: " << (form.isFormSigned() ? "Yes" : "No")
           << "\n\t|--> Sign Grade: " << form.getSignGrade() << "\n\t|--> Execute Grade: " << form.getExecGrade() << std::endl;
    return output;
}