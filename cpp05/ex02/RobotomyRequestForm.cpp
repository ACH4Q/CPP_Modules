#include "RobotomyRequestFor.hpp"

RobotomyRequestFor::RobotomyRequestFor(const std::string& _target) : AForm("Robottomyrequest Form", 72,45) , target(_target) {}

RobotomyRequestFor::RobotomyRequestFor(const RobotomyRequestFor& other) : AForm(other) , target(other.target) {}

RobotomyRequestFor::~RobotomyRequestFor() {}