
#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include <cstring>

class Contacts
{
private:

    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string darksecret;

public:

    void set_firstname(std::string firstname);
    void set_lastname(std::string lastname);
    void set_nickname(std::string nickname);
    void set_phonenumber(std::string phonenumber);
    void set_darksecret(std::string darksecret);

    std::string get_firstname();
    std::string get_lastname();
    std::string get_nickname();
    std::string get_phonenumber();
    std::string get_darksecret();

};


#endif
