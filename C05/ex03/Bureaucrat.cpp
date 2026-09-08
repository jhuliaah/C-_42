

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(MIN_GRADE) {} 

Bureaucrat::Bureaucrat(std::string const &name, int grade)
: _name(name)
{
    if (grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: _name(other._name)
{
    _grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this !=&other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::get_name() const 
{
    return (_name);
}

int Bureaucrat::get_grade() const
{
    return (_grade);
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    _grade--;

}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

void Bureaucrat::signForm(AForm &_form)
{
    try
    {
        _form.beSigned(*this);
        std::cout << this->get_name() << " assinou " << _form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->get_name() << " não conseguiu assinar " << _form.get_name()
                   << " porque " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->get_name() << " executou " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->get_name() << " não conseguiu executar " << form.get_name()
                   << " porque " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj) {
    os << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << ".";
    
    return os; 
}