
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

static AForm *createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardon(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    struct FormEntry
    {
        std::string name;
        AForm *(*create)(std::string const &);
    };

    static const FormEntry forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPresidentialPardon}
    };
    static const size_t formsCount = sizeof(forms) / sizeof(forms[0]);

    for (size_t i = 0; i < formsCount; i++)
    {
        if (forms[i].name == formName)
        {
            AForm *form = forms[i].create(target);
            std::cout << "Intern cria " << form->get_name() << std::endl;
            return (form);
        }
    }
    std::cout << "Intern não conseguiu encontrar um formulário chamado " << formName << std::endl;
    return (NULL);
}
