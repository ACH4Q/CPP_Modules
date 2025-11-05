#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat highGradeBureaucrat("Hermes", 30);
    Bureaucrat lowGradeBureaucrat("Zoidberg", 150);
    Form taxForm("Form 28B", 50, 25);

    std::cout << "\n--- INITIAL STATUS ---\n";
    std::cout << highGradeBureaucrat << std::endl;
    std::cout << lowGradeBureaucrat << std::endl;
    std::cout << taxForm << std::endl;

    std::cout << "\n--- TEST 1: LOW GRADE SIGNING (FAIL) ---\n";
    lowGradeBureaucrat.signForm(taxForm);
    std::cout << "Form status after attempt: " << taxForm << std::endl;

    std::cout << "\n--- TEST 2: HIGH GRADE SIGNING (SUCCESS) ---\n";
    highGradeBureaucrat.signForm(taxForm);
    std::cout << "Form status after attempt: " << taxForm << std::endl;
    
    std::cout << "\n--- TEST 3: SIGNING AN ALREADY SIGNED FORM ---\n";
    highGradeBureaucrat.signForm(taxForm);
    std::cout << "Form status after attempt: " << taxForm << std::endl;

    return 0;
}