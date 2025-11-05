#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("Robotomy Request Form", 72,45), target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executing() const
{
    std::cout << "* BZZZZZZZ... DRILLING NOISES... BZZZZZZZ *" << std::endl;
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy on " << this->target << " has failed." << std::endl;
}