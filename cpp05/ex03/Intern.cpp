#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}


Intern::Intern(const Intern& other) { (void)other; }

Intern Intern::operator=(const Intern& other) {(void)other; return(*this);}

const char* Intern::FormNotFound::what() const throw()
{
    return "Form not found";
}

AForm *Intern::makeForm(const std::string& Formname,const std::string& target)
{
    int FormIndex = -1;
    AForm* newForm = NULL;
    std::string validForms[] = {"shrubbery creation","robotomy creation", "presidential pardon"};

    for (size_t i = 0; i < 3; i++)
    {
        if (Formname == validForms[i])
        {
            FormIndex = i;
            break;
        }        
    }

    switch (FormIndex)
    {
    case 0:
    newForm = new RobotomyRequestForm(target);
        break;
    case 1:
    newForm = new PresidentialPardonForm(target);
        break;
    case 2:
    newForm = new ShrubberyCreationForm(target);
        break;
    default:
        throw Intern::FormNotFound();
    }

    std::cout << "Intern creates " << newForm->GetName() << std::endl;
    return (newForm);
}