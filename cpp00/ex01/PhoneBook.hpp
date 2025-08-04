#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include "Contacts.hpp"
#include <iomanip>
#include <cstdlib>

#define Enter(a,b,c,d) std::cout << std::setw(10) << a << "|" << std::setw(10) << b << "|" << std::setw(10) << c << "|" << std::setw(10) << d << "|\n";
#define Display(a,b,c,d,e) std::cout << "\nFirst name: " << a << "\n" << "Last name: " << b << "\n" << "Nickname: " << c << "\n"  << "Phone number: " << d << "\n" << "Darkest secret: " << e << "\n" << std::endl;

class PhoneBook
{
private:

    Contacts Contacts_class[8];
    static int  index;
public:

    int The_Prompt(const std::string& prompt, int (*validate)(const std::string&) , std::string& output);
    void AddContact();
	int			Check(const std::string &index);
	int			DisplayContacts();
	void		DisplayContact();

};

int			validateName(const std::string &str);
int			validateNickName(const std::string &str1);
int			validatePhoneNumber(const std::string &str2);

#endif