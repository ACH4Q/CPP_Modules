#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool boolean;
    const int grade_sign;
    const int grade_exec;
public:
    Form();
    Form(const Form& other);
    Form(const std::string& name, int grade_sign, int grade_exec);
    Form& operator=(const Form& other);
    ~Form();

    std::string GetName() const;
    bool GetIsSigned() const;
    int GetGradeSign() const;
    int GetGradeExec() const;
    void beSigned(const Bureaucrat& bureaucrat);

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
std::ostream& operator<<(std::ostream& os,const Form& F);



#endif