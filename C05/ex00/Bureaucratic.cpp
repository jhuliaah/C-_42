

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(std::string const &name, int const &grade)
: _name(name)
{
    if (grade < MAX_GRADE)
        Bureaucrat::GradeTooHighException();
    else if (grade > MIN_GRADE)
        Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name)
{
    _grade = other._grade;
}

Bureaucrat::~Bureaucrat() {}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << ".";
    
    return os; 
}