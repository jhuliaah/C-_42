
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
: _name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE)
{}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw AForm::GradeTooHighException();
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
: _name(other._name), _signed(other._signed),
  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

AForm::~AForm() {}

std::string AForm::get_name() const
{
    return (_name);
}

int AForm::get_grade_to_sign() const
{
    return (_gradeToSign);
}

int AForm::get_grade_to_execute() const
{
    return (_gradeToExecute);
}

bool AForm::get_form_status() const
{
    return (_signed);
}

void AForm::beSigned(Bureaucrat &_bureaucrat)
{
    if (_bureaucrat.get_grade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.get_grade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    this->executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "Form " << obj.get_name() << ", grade to sign " << obj.get_grade_to_sign()
       << ", grade to execute " << obj.get_grade_to_execute()
       << ", signed: " << (obj.get_form_status() ? "yes" : "no") << ".";
    return os;
}
