
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testValidBureaucrat() {
    std::cout << "\n=== TESTE 1: Burocrata Válido e Operador << ===" << std::endl;
    try {
        Bureaucrat alex("Alex", 75);
        std::cout << alex << std::endl;

        std::cout << "Incrementando grau..." << std::endl;
        alex.incrementGrade();
        std::cout << alex << std::endl;

        std::cout << "Decrementando grau..." << std::endl;
        alex.decrementGrade();
        std::cout << alex << std::endl;
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção inesperada: " << e.what() << std::endl;
    }
}

void testCopyAndAssignment() {
    std::cout << "\n=== TESTE 2: Construtor de Cópia e Operador = ===" << std::endl;
    try {
        Bureaucrat original("Original", 42);
        Bureaucrat copia(original); // Construtor de Cópia
        Bureaucrat atribuido("Atribuido", 100);

        std::cout << "Original:  " << original << std::endl;
        std::cout << "Copia:     " << copia << std::endl;
        std::cout << "Antes de =: " << atribuido << std::endl;

        atribuido = original; // Operador de Atribuição (=)
        std::cout << "Depois de =: " << atribuido << " (Note que apenas a grade muda, name e const)" << std::endl;
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção inesperada: " << e.what() << std::endl;
    }
}

void testGradeTooHighOnCreation() {
    std::cout << "\n=== TESTE 3: Criar com Grade Muito Alta (< 1) ===" << std::endl;
    try {
        Bureaucrat boss("Chefe", 0);
        std::cout << boss << std::endl; // Não deve chegar aqui
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção Capturada com sucesso: " << e.what() << std::endl;
    }
}

void testGradeTooLowOnCreation() {
    std::cout << "\n=== TESTE 4: Criar com Grade Muito Baixa (> 150) ===" << std::endl;
    try {
        Bureaucrat estagiario("Estagiario", 151);
        std::cout << estagiario << std::endl; // Não deve chegar aqui
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção Capturada com sucesso: " << e.what() << std::endl;
    }
}

void testOverflowIncrement() {
    std::cout << "\n=== TESTE 5: Incrementar além do limite (Grade 1 -> 0) ===" << std::endl;
    try {
        Bureaucrat presidente("Presidente", 1);
        std::cout << presidente << std::endl;
        
        std::cout << "Tentando promover o Presidente..." << std::endl;
        presidente.incrementGrade(); // Deve lançar GradeTooHighException
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção Capturada com sucesso: " << e.what() << std::endl;
    }
}

void testUnderflowDecrement() {
    std::cout << "\n=== TESTE 6: Decrementar além do limite (Grade 150 -> 151) ===" << std::endl;
    try {
        Bureaucrat novato("Novato", 150);
        std::cout << novato << std::endl;
        
        std::cout << "Tentando rebaixar o Novato..." << std::endl;
        novato.decrementGrade(); // Deve lançar GradeTooLowException
    } 
    catch (const std::exception &e) {
        std::cout << "Exceção Capturada com sucesso: " << e.what() << std::endl;
    }
}

void testFormCreation() {
    std::cout << "\n=== TESTE 7: Criação de Form (válido e inválido) ===" << std::endl;
    try {
        Form valido("Formulario Valido", 50, 100);
        std::cout << valido << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Exceção inesperada: " << e.what() << std::endl;
    }

    try {
        Form invalido("Formulario Invalido", 0, 100);
        std::cout << invalido << std::endl; // Não deve chegar aqui
    }
    catch (const std::exception &e) {
        std::cout << "Exceção Capturada com sucesso: " << e.what() << std::endl;
    }
}

void testSignFormSuccess() {
    std::cout << "\n=== TESTE 8: Assinar Form com sucesso ===" << std::endl;
    Bureaucrat chefe("Chefe", 10);
    Form form("Formulario", 50, 100);

    std::cout << chefe << std::endl;
    std::cout << form << std::endl;
    chefe.signForm(form);
    std::cout << form << std::endl;
}

void testSignFormFailure() {
    std::cout << "\n=== TESTE 9: Assinar Form sem grade suficiente ===" << std::endl;
    Bureaucrat estagiario("Estagiario", 150);
    Form form("Formulario", 50, 100);

    std::cout << estagiario << std::endl;
    std::cout << form << std::endl;
    estagiario.signForm(form);
    std::cout << form << std::endl;
}

int main() {
    testValidBureaucrat();
    testCopyAndAssignment();
    testGradeTooHighOnCreation();
    testGradeTooLowOnCreation();
    testOverflowIncrement();
    testUnderflowDecrement();
    testFormCreation();
    testSignFormSuccess();
    testSignFormFailure();

    return 0;
}