#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

const char* Intern::FormNotFound::what() const throw()
{
    return "Intern Error: Form not found";
}

AForm *Intern::makeForm(const std::string& Formname,const std::string& target)
{
    AForm* newForm = NULL;
    std::string validForms[] =
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int formIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        if (Formname == validForms[i])
        {
            formIndex = i;
            break;
        }
    }

    switch (formIndex)
    {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::FormNotFound();
    }

    std::cout << "Intern creates " << newForm->GetName() << std::endl;
    return newForm;
}