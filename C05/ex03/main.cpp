
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testMakeValidForms() {
    std::cout << "\n=== TESTE 1: Intern cria os 3 formulários válidos ===" << std::endl;
    Intern someRandomIntern;
    Bureaucrat chefe("Chefe", 1);

    AForm *forms[3];
    forms[0] = someRandomIntern.makeForm("shrubbery creation", "casa");
    forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
    forms[2] = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

    for (int i = 0; i < 3; i++) {
        if (forms[i]) {
            chefe.signForm(*forms[i]);
            chefe.executeForm(*forms[i]);
            delete forms[i];
        }
    }
}

void testMakeUnknownForm() {
    std::cout << "\n=== TESTE 2: Intern tenta criar formulário inexistente ===" << std::endl;
    Intern someRandomIntern;

    AForm *form = someRandomIntern.makeForm("pedido de robotomia", "Bender");
    if (!form)
        std::cout << "form é NULL, como esperado." << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    testMakeValidForms();
    testMakeUnknownForm();

    return 0;
}
