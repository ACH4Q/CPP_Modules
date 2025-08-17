#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n I really do!" << std::endl;
}
void Harl::info()
{
	std::cout <<  "I cannot believe adding extra bacon costs more money.\n You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free.\n I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(const std::string level)
{
    void(Harl::*func[4])() = {&Harl::debug , &Harl::info , &Harl::warning , &Harl::error};

    if (level == "DEBUG")
    {
        (this->*func[0])();
    }
    else if (level == "INFO")
    {
        (this->*func[1])();
    }
    else if (level == "WARNING")
    {
        (this->*func[2])();
    }
    else if (level == "ERROR")
    {
        (this->*func[3])();
    }
    else
        std::cout << "invalid level" << std::endl;

}