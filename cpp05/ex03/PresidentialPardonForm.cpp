#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25,5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executing() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}