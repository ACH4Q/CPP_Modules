#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern operator=(const Intern& other);
    ~Intern();
    AForm *makeForm(const std::string& Formname,const std::string& target);

    class FormNotFound : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };  
};


#endif