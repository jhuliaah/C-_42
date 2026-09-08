
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXECUTE_GRADE 45

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Default", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXECUTE_GRADE), _target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
: AForm("RobotomyRequestForm", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXECUTE_GRADE), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* BZZZZTT DRILLING NOISES BZZZZTT *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "robotomy failed for " << _target << "!" << std::endl;
}
