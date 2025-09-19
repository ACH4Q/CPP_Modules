#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

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
    Form& operator=(const Form& other);
    ~Form();

    std::string GetName() const;
    bool GetBool();
    int GetGradeSign() const;
    int GetGradeExec() const;
    class GradeTooHighException : public std::exception
    {
        public :
            const char * GradeTooHighException::what() throw();
    };
    class GradeTooLowException : public std::exception
    {
        public :
            const char* GradeTooLowException::what() throw();
    };

};
std::ostream&  operator<<(std::ostream& os,const Form& other);



#endif