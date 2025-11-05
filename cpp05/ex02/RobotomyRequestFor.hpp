#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"

class RobotomyRequestFor : public AForm 
{
private:
    std::string target;
public:
    RobotomyRequestFor(const std::string& target);
    RobotomyRequestFor(const RobotomyRequestFor& other);
    ~RobotomyRequestFor();
};

#endif