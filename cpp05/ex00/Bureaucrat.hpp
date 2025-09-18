#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exeption>


class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    std::string GetName() const;
    int GetGrade();

    class GradeTooLowException : public exeption
    {
        virtual const char* what() const throw();
    }
    class GradeTooHighException : public exeption
    {
        virtual const char* what() const throw();
    }

};




#endif