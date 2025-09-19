#include "Form.hpp"

Form::Form(): name("Default Form") , boolean(0) , grade_sign(150) , grade_exec(150) {}

Form::Form(const Form& other)
{
    name
}

Form::Form(const std::string& name, const int grade_sign,const int grade_exec)
{
    
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->boolean = other.boolean;
        this->name == other.name;
        if (grade_sign < 1&& grade_exec < 1)
        {
            throw Form::GradeTooHighException::what() throw();
        }
        else if (grade_exec > 150 && grade_sign > 150)
        {
            throw Form::GradeTooLowException::what() throw();
        }
    } 
}

Form::~Form()
{

}

std::string Form::GetName() const
{

}

bool Form::GetBool()
{

}

int Form::GetGradeSign() const
{

}

int Form::GetGradeExec() const
{

}

void Form::beSigned(const Bureaucrat& bureaucrat)
{

}

std::ostream& operator<<(std::ostream& os,const Form& F)
{

}

