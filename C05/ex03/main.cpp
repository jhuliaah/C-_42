
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testMakeValidForms() {
    std::cout << "\n=== TEST 1: Intern creates the 3 valid forms ===" << std::endl;
    Intern someRandomIntern;
    Bureaucrat chefe("Chefe", 1);

    AForm *forms[3];
    forms[0] = someRandomIntern.makeForm("shrubbery creation", "house");
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
    std::cout << "\n=== TEST 2: Intern tries to create a nonexistent form ===" << std::endl;
    Intern someRandomIntern;

    AForm *form = someRandomIntern.makeForm("robotomy request pt", "Bender");
    if (!form)
        std::cout << "form is NULL, as expected." << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    testMakeValidForms();
    testMakeUnknownForm();

    return 0;
}
