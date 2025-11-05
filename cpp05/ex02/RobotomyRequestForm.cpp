#include "RobotomyRequestFor.hpp"

RobotomyRequestFor::RobotomyRequestFor(const std::string& _target) : AForm("Robottomyrequest Form", 72,45) , target(_target) {}

RobotomyRequestFor::RobotomyRequestFor(const RobotomyRequestFor& other) : AForm(other) , target(other.target) {}

RobotomyRequestFor::~RobotomyRequestFor() {}

void RobotomyRequestFor::executing()
{
    std::cout << "BZZZZZZZ SOME DARLING NOISE" << std::endl;
    if (std::rand() % 2)
        std::cout << this->target << "has succeded to be robotic" << std::endl;
    else
        std::cout << this->target << "has failed to be robotic"<< std::endl;
    
}