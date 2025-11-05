#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
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
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooLowException();
    grade--;
}

void Bureaucrat::DecrementGrade()
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::signForm(AForm& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << "is signed" << form.GetName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << "cannot be signed because" << form.GetName() << e.what()  << std::endl;
    }
    
}
void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->GetName() << " executed " << form.GetName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->GetName() << " couldn't execute " << form.GetName() << " because: " << e.what() << std::endl;
    }
    
}