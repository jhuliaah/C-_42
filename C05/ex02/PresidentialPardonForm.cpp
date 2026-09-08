
#include "PresidentialPardonForm.hpp"

#define PARDON_SIGN_GRADE 25
#define PARDON_EXECUTE_GRADE 5

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Default", PARDON_SIGN_GRADE, PARDON_EXECUTE_GRADE), _target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
: AForm("PresidentialPardonForm", PARDON_SIGN_GRADE, PARDON_EXECUTE_GRADE), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), _target(other._target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
