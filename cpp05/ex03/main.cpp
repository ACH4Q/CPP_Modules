#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator for RobotomyRequestForm
    std::srand(std::time(0));

    // Create some bureaucrats
    Bureaucrat highGrade("Head Bureaucrat", 1);
    Bureaucrat midGrade("Mid-Level Manager", 40);
    Bureaucrat lowGrade("Intern", 140);

    // Create one of each form
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "\n--- SHRUBBERY FORM TESTS ---\n";
    lowGrade.signForm(shrub);
    lowGrade.executeForm(shrub); // Fails, grade 140 is not high enough (needs 137)
    midGrade.executeForm(shrub);

    std::cout << "\n--- ROBOTOMY FORM TESTS ---\n";
    midGrade.signForm(robot);
    midGrade.executeForm(robot);
    highGrade.executeForm(robot); // Should also work

    std::cout << "\n--- PARDON FORM TESTS ---\n";
    highGrade.executeForm(pardon); // Fails, form not signed
    highGrade.signForm(pardon);
    highGrade.executeForm(pardon);

    return 0;
}