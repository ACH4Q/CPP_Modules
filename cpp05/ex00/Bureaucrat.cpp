#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat() : grade(150) , name("Default")
{
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::GetName() const
{
    return(this->name);
}

int Bureaucrat::GetGrade()
{
    return(this->grade);
}

void Bureaucrat::GradeTooHighException()
{
    
}