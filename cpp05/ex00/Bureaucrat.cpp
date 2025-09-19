#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat()
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& _name, int grade) : name(_name)
{
    if (grade < 1)
    {
        Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
    std::cout << "" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    if (this != &other)
    {
        *this = other;
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
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

void Bureaucrat::IncrementGrade()
{
    
}

void Bureaucrat::DecrementGrade()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade Too High");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade Too Low");
}