#include "Contacts.hpp"


void Contacts::set_firstname(std::string firstname)
{
    Contacts::firstname = firstname;
}

void Contacts::set_lastname(std::string lastname)
{
    Contacts::lastname = lastname;
}

void Contacts::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contacts::set_phonenumber(std::string phonenumber)
{
    Contacts::phonenumber = phonenumber;
}

void Contacts::set_darksecret(std::string darksecret)
{
    Contacts::darksecret = darksecret;
}

std::string Contacts::get_firstname()
{
    return(this->firstname);
}

std::string Contacts::get_lastname()
{
    return(this->lastname);
}

std::string Contacts::get_nickname()
{
    return(this->nickname);
}

std::string Contacts::get_phonenumber()
{
    return(this->phonenumber);
}

std::string Contacts::get_darksecret()
{
    return(this->darksecret);
}
