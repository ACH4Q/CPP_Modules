#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default Form"), boolean(false), grade_sign(150), grade_exec(150)
{
}

Form::Form(const std::string& name, int grade_sign, int grade_exec) :
    name(name),
    boolean(false),
    grade_sign(grade_sign),
    grade_exec(grade_exec)
{
    if (grade_sign < 1 || grade_exec < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) :
    name(other.name),
    boolean(other.boolean),
    grade_sign(other.grade_sign),
    grade_exec(other.grade_exec)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->boolean = other.boolean;
    }
    return *this;
}

Form::~Form()
{
}

std::string Form::GetName() const
{
    return this->name;
}

bool Form::GetIsSigned() const
{
    return this->boolean;
}

int Form::GetGradeSign() const
{
    return this->grade_sign;
}

int Form::GetGradeExec() const
{
    return this->grade_exec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.GetGrade() > this->grade_sign)
    {
        throw Form::GradeTooLowException();
    }
    this->boolean = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Form Error: The grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Form Error: The grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Form& F)
{
    os << "Form: " << F.GetName() << ", Signed: ";
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