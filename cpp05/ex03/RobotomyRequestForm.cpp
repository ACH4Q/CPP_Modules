#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& _target) : AForm("robotomy request", 72,45) , target(_target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) , target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executing() const
{
    std::cout << "BZZZZZZZ SOME DARLING NOISE" << std::endl;
    if (rand() % 2)
        std::cout << this->target << "has succeded to be robotic" << std::endl;
    else
        std::cout << this->target << "has failed to be robotic"<< std::endl;
}