#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default AForm"), boolean(false), grade_sign(150), grade_exec(150)
{
}

AForm::AForm(const std::string& name, int grade_sign, int grade_exec) :
    name(name),
    boolean(false),
    grade_sign(grade_sign),
    grade_exec(grade_exec)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw AForm::GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
    name(other.name),
    boolean(other.boolean),
    grade_sign(other.grade_sign),
    grade_exec(other.grade_exec)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->boolean = other.boolean;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::GetName() const
{
    return this->name;
}

bool AForm::GetIsSigned() const
{
    return this->boolean;
}

int AForm::GetGradeSign() const
{
    return this->grade_sign;
}

int AForm::GetGradeExec() const
{
    return this->grade_exec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.GetGrade() > this->grade_sign)
    {
        throw AForm::GradeTooLowException();
    }
    this->boolean = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("AForm Error: The grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("AForm Error: The grade is too low!");
}
const char* AForm::FormNotSignedException::what() const throw() 
{
     return "AForm Error: Form is not signed!";
}
std::ostream& operator<<(std::ostream& os, const AForm& F)
{
    os << "AForm: " << F.GetName() << ", Signed: ";
    if (F.GetIsSigned())
    {
        os << "Yes";
    }
    else
    {
        os << "No";
    }
    os << ", Grade to Sign: " << F.GetGradeSign() << ", Grade to Execute: " << F.GetGradeExec();
       
    return os;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!this->boolean)
        throw AForm::FormNotSignedException();
    if (executor.GetGrade() > this->grade_exec)
        throw AForm::GradeTooLowException();
    this->executing();
}