
#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define SHRUBBERY_SIGN_GRADE 145
#define SHRUBBERY_EXECUTE_GRADE 137

ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("Default", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXECUTE_GRADE), _target("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
: AForm("ShrubberyCreationForm", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXECUTE_GRADE), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), _target(other._target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    file << "        &&&&&&&\n";
    file << "      &&&&&&&&&&&\n";
    file << "     &&&&&&&&&&&&&&\n";
    file << "    &&&&&&&&&&&&&&&&\n";
    file << "        &&&&&&&\n";
    file << "        &&&&&&&\n";
    file.close();
}
