#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool boolean;
    const int grade_sign;
    const int grade_exec;
public:
    AForm();
    AForm(const AForm& other);
    AForm(const std::string& name, int grade_sign, int grade_exec);
    AForm& operator=(const AForm& other);
    ~AForm();

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
    virtual int execute(Bureaucrat const & executor) const = 0;
};
std::ostream& operator<<(std::ostream& os,const AForm& F);



#endif