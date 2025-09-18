#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat& operator<<(const Bureaucrat& other);
    std::string GetName() const;
    int GetGrade();
    void GradeTooHighException();
    void GradeTooLowException();
};




#endif