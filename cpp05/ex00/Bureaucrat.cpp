#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat")
{
    std::cout << "Bureaucrat " << name << "is created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << name << "is destoryed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& _name, int grade) : name(_name)
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade = grade;
    std::cout << "Bureaucrat " << name << "been created by grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    this->grade = other.grade;
    std::cout << "copy constructor called for Bureaucrat " << name << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        *this = other;
    }
    std::cout << "Bureaucrat " << name << "assigned value" << std::endl;
    return *this;
}

std::string Bureaucrat::GetName() const
{
    return(this->name);
}

int Bureaucrat::GetGrade() const
{
    if (grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    return(this->grade);
}

void Bureaucrat::IncrementGrade()
{
    grade--;
}

void Bureaucrat::DecrementGrade()
{
    if (grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade Too Low");
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.GetName() << "bureaucrat grade is " << bureaucrat.GetGrade();
    return os;
}