#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string& _name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    std::string GetName() const;
    int GetGrade() const;
    void IncrementGrade();
    void DecrementGrade();
    void signForm(Form& form);

    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        public :
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
