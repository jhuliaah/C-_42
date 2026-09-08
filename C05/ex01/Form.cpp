
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
: _name("Default"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE)
{}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
        throw Form::GradeTooHighException();
    if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other)
: _name(other._name), _signed(other._signed),
  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_signed = other._signed;
    return (*this);
}

Form::~Form() {}

std::string Form::get_name() const
{
    return (_name);
}

int Form::get_grade_to_sign() const
{
    return (_gradeToSign);
}

int Form::get_grade_to_execute() const
{
    return (_gradeToExecute);
}

bool Form::get_form_status() const
{
    return (_signed);
}

void Form::beSigned(Bureaucrat &_bureaucrat)
{
    if (_bureaucrat.get_grade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "Form " << obj.get_name() << ", grade to sign " << obj.get_grade_to_sign()
       << ", grade to execute " << obj.get_grade_to_execute()
       << ", signed: " << (obj.get_form_status() ? "yes" : "no") << ".";
    return os;
}
