
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testShrubbery() {
    std::cout << "\n=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    Bureaucrat chefe("Chefe", 1);
    ShrubberyCreationForm form("house");

    std::cout << form << std::endl;
    chefe.signForm(form);
    chefe.executeForm(form);
}

void testRobotomy() {
    std::cout << "\n=== TEST 2: RobotomyRequestForm ===" << std::endl;
    Bureaucrat chefe("Chefe", 1);
    RobotomyRequestForm form("Bender");

    std::cout << form << std::endl;
    chefe.signForm(form);
    chefe.executeForm(form);
    chefe.executeForm(form);
}

void testPresidentialPardon() {
    std::cout << "\n=== TEST 3: PresidentialPardonForm ===" << std::endl;
    Bureaucrat chefe("Chefe", 1);
    PresidentialPardonForm form("Arthur Dent");

    std::cout << form << std::endl;
    chefe.signForm(form);
    chefe.executeForm(form);
}

void testExecuteWithoutSigning() {
    std::cout << "\n=== TEST 4: Execute without signing ===" << std::endl;
    Bureaucrat chefe("Chefe", 1);
    ShrubberyCreationForm form("garden");

    chefe.executeForm(form);
}

void testExecuteGradeTooLow() {
    std::cout << "\n=== TEST 5: Execute with insufficient grade ===" << std::endl;
    Bureaucrat chefe("Chefe", 1);
    Bureaucrat estagiario("Estagiario", 150);
    PresidentialPardonForm form("Ford Prefect");

    chefe.signForm(form);
    estagiario.executeForm(form);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    testShrubbery();
    testRobotomy();
    testPresidentialPardon();
    testExecuteWithoutSigning();
    testExecuteGradeTooLow();

    return 0;
}
