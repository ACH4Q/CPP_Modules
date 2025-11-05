#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    // --- Setup ---
    Intern someRandomIntern;
    Bureaucrat highGradeBureaucrat("Zapp Brannigan", 5);

    // Pointers to hold the forms our Intern will create
    AForm* robotomyForm = NULL;
    AForm* pardonForm = NULL;
    AForm* shrubberyForm = NULL;
    AForm* nonExistentForm = NULL;

    std::cout << "--- TEST 1: INTERN CREATING FORMS ---\n";

    try
    {
        // Test successful creation of all three forms
        std::cout << "\nAttempting to create a RobotomyRequestForm...\n";
        robotomyForm = someRandomIntern.makeForm("robotomy request", "Bender");

        std::cout << "\nAttempting to create a PresidentialPardonForm...\n";
        pardonForm = someRandomIntern.makeForm("presidential pardon", "Fry");

        std::cout << "\nAttempting to create a ShrubberyCreationForm...\n";
        shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "The Garden");

        // Test failure case for a form that does not exist
        std::cout << "\nAttempting to create a non-existent form...\n";
        nonExistentForm = someRandomIntern.makeForm("resign from duty form", "Philip");
    }
    catch (const std::exception& e)
    {
        // This catch block should execute for the non-existent form
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: BUREAUCRAT INTERACTING WITH CREATED FORMS ---\n";

    // We check if the pointers are not NULL before using them.
    // This is good practice, especially since one of them failed to be created.
    if (robotomyForm)
    {
        std::cout << "\n--- Interacting with Robotomy Form ---\n";
        highGradeBureaucrat.signForm(*robotomyForm);
        highGradeBureaucrat.executeForm(*robotomyForm);
    }
    
    if (pardonForm)
    {
        std::cout << "\n--- Interacting with Pardon Form ---\n";
        highGradeBureaucrat.signForm(*pardonForm);
        highGradeBureaucrat.executeForm(*pardonForm);
    }
    
    if (shrubberyForm)
    {
        std::cout << "\n--- Interacting with Shrubbery Form ---\n";
        highGradeBureaucrat.signForm(*shrubberyForm);
        highGradeBureaucrat.executeForm(*shrubberyForm);
    }

    if (nonExistentForm == NULL)
    {
        std::cout << "\n--- Verifying Non-Existent Form ---\n";
        std::cout << "As expected, the pointer for the non-existent form is NULL.\n";
    }


    // --- Cleanup: Free the memory allocated by the Intern ---
    std::cout << "\n--- CLEANING UP MEMORY ---\n";
    delete robotomyForm;
    delete pardonForm;
    delete shrubberyForm;
    // No need to delete nonExistentForm as it is NULL

    return 0;
}