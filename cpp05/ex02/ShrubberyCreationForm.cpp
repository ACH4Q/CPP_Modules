#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& _target): AForm("Shrubbery Form",145,137) , target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executing()
{

}

