#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>


class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    std::string GetName() const;
    int GetGrade();
    void IncrementGrade();
    void DecrementGrade();

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

std::ostream& operator<<(std::ostream& os,const Bureaucrat& Bureaucrat);



#endif