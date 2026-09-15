
#include "Bureaucrat.hpp"
#include <iostream>

void testValidBureaucrat() {
    std::cout << "\n=== TEST 1: Valid Bureaucrat and << Operator ===" << std::endl;
    try {
        Bureaucrat alex("Alex", 75);
        std::cout << alex << std::endl;

        std::cout << "Incrementing grade..." << std::endl;
        alex.incrementGrade();
        std::cout << alex << std::endl;

        std::cout << "Decrementing grade..." << std::endl;
        alex.decrementGrade();
        std::cout << alex << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment() {
    std::cout << "\n=== TEST 2: Copy Constructor and = Operator ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copia(original); // Copy constructor
        Bureaucrat atribuido("Atribuido", 100);

        std::cout << "Original:  " << original << std::endl;
        std::cout << "Copy:      " << copia << std::endl;
        std::cout << "Before =: " << atribuido << std::endl;

        atribuido = original; // Assignment operator (=)
        std::cout << "After =: " << atribuido << " (Note that only the grade changes, name is const)" << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testGradeTooHighOnCreation() {
    std::cout << "\n=== TEST 3: Create with Grade Too High (< 1) ===" << std::endl;
    try {
        Bureaucrat boss("Chefe", 0);
        std::cout << boss << std::endl; // Should not reach here
    }
    catch (const std::exception &e) {
        std::cout << "Exception successfully caught: " << e.what() << std::endl;
    }
}

void testGradeTooLowOnCreation() {
    std::cout << "\n=== TEST 4: Create with Grade Too Low (> 150) ===" << std::endl;
    try {
        Bureaucrat estagiario("Estagiario", 151);
        std::cout << estagiario << std::endl; // Should not reach here
    }
    catch (const std::exception &e) {
        std::cout << "Exception successfully caught: " << e.what() << std::endl;
    }
}

void testOverflowIncrement() {
    std::cout << "\n=== TEST 5: Increment beyond the limit (Grade 1 -> 0) ===" << std::endl;
    try {
        Bureaucrat presidente("Presidente", 1);
        std::cout << presidente << std::endl;

        std::cout << "Trying to promote the President..." << std::endl;
        presidente.incrementGrade(); // Should throw GradeTooHighException
    }
    catch (const std::exception &e) {
        std::cout << "Exception successfully caught: " << e.what() << std::endl;
    }
}

void testUnderflowDecrement() {
    std::cout << "\n=== TEST 6: Decrement beyond the limit (Grade 150 -> 151) ===" << std::endl;
    try {
        Bureaucrat novato("Novato", 150);
        std::cout << novato << std::endl;

        std::cout << "Trying to demote the Intern..." << std::endl;
        novato.decrementGrade(); // Should throw GradeTooLowException
    }
    catch (const std::exception &e) {
        std::cout << "Exception successfully caught: " << e.what() << std::endl;
    }
}

int main() {
    testValidBureaucrat();
    testCopyAndAssignment();
    testGradeTooHighOnCreation();
    testGradeTooLowOnCreation();
    testOverflowIncrement();
    testUnderflowDecrement();

    return 0;
}