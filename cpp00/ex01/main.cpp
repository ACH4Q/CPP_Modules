#include <iostream>
#include "PhoneBook.hpp"

int main(int ac, char **av)
{
    (void)av;
    PhoneBook phoneBook;
    std::string prompt;

    if (ac == 1)
    {
        std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
        std::cout << "----------------------------------" << std::endl;
        do {
            if (std::cin.fail())
                break;
            std::cout << "Enter your command [ADD | SEARCH | EXIT]: ";
            if (!std::getline(std::cin, prompt))
                break;
            if (prompt == "ADD")
                phoneBook.AddContact();
            else if (prompt == "SEARCH")
                phoneBook.DisplayContact();
            else if (prompt != "EXIT")
                std::cout << "Invalid command. Please use ADD, SEARCH or EXIT." << std::endl;
        } while (prompt != "EXIT");
        std::cout << "PhoneBook closed. All contacts lost forever!" << std::endl;
        return (0);
    }
    return (1);
}
