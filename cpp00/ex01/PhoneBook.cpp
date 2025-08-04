#include "PhoneBook.hpp"

int PhoneBook::index = 0;

int validateName(const std::string &str)
{
    if (str.length() < 2)
    {
        std::cerr << "Error: Name must be at least 2 characters long" << std::endl;
        return 0;
    }
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
        {
            std::cerr << "Error: Name can only contain letters, spaces and hyphens" << std::endl;
            return 0;
        }
    }
    return 1;
}

int validateNickName(const std::string &str1)
{
    if (str1.empty())
    {
        std::cerr << "Error: Nickname cannot be empty" << std::endl;
        return 0;
    }
    for (size_t i = 0; i < str1.length(); i++)
    {
        if (!isalnum(str1[i]))
        {
            std::cerr << "Error: Nickname can only contain alphanumeric characters" << std::endl;
            return 0;
        }
    }
    return 1;
}

int validatePhoneNumber(const std::string &str2)
{
    if (str2.length() < 4)
    {
        std::cerr << "Error: Phone number must be at least 4 digits" << std::endl;
        return 0;
    }
    for (size_t i = 0; i < str2.length(); i++)
    {
        if (!isdigit(str2[i]))
        {
            std::cerr << "Error: Phone number can only contain digits" << std::endl;
            return 0;
        }
    }
    return 1;
}

std::string substring(const std::string &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int PhoneBook::Check(const std::string& index)
{
    if (index.length() != 1 || index[0] < '0' || index[0] > '7')
    {
        std::cerr << "Error: Index must be between 0 and 7" << std::endl;
        return -1;
    }
    
    int i = index[0] - '0';
    if (Contacts_class[i].get_firstname().empty())
    {
        std::cerr << "Error: No contact found at index " << i << std::endl;
        return -1;
    }
    return i;
}

int PhoneBook::The_Prompt(const std::string& prompt, int (*validate)(const std::string&), std::string& output)
{
    while (true)
    {
        std::cout << prompt << ": ";
        if (!std::getline(std::cin, output))
            return 0;
        if (output.empty())
        {
            std::cerr << "Error: Field cannot be empty" << std::endl;
            continue;
        }
        if (!validate(output))
            continue;
        return 1;
    }
}

void PhoneBook::AddContact()
{
    std::string input;

    if (!The_Prompt("Enter first name", validateName, input))
        return;
    Contacts_class[index].set_firstname(input);
    
    if (!The_Prompt("Enter last name", validateName, input))
        return;
    Contacts_class[index].set_lastname(input);
    
    if (!The_Prompt("Enter nickname", validateNickName, input))
        return;
    Contacts_class[index].set_nickname(input);
    
    if (!The_Prompt("Enter phone number", validatePhoneNumber, input))
        return;
    Contacts_class[index].set_phonenumber(input);
    
    if (!The_Prompt("Enter darkest secret", validateNickName, input))
        return;
    Contacts_class[index].set_darksecret(input);
    
    std::cout << "Contact added successfully!" << std::endl;
    index = (index + 1) % 8;
}

int PhoneBook::DisplayContacts()
{
    if (Contacts_class[0].get_firstname().empty())
    {
        std::cerr << "No contacts found in phonebook" << std::endl;
        return 0;
    }
    Enter("Index", "First Name", "Last Name", "Nickname");
    for (int i = 0; i < 8 && !Contacts_class[i].get_firstname().empty(); i++)
    {
        Enter(i, 
              substring(Contacts_class[i].get_firstname()),
              substring(Contacts_class[i].get_lastname()),
              substring(Contacts_class[i].get_nickname()));
    }
    return 1;
}

void PhoneBook::DisplayContact()
{
    std::string input;
    int i;

    if (!DisplayContacts())
        return;
    std::cout << "\nEnter contact index to display: ";
    while (true)
    {
        if (!std::getline(std::cin, input))
            return;
        i = Check(input);
        if (i != -1)
            break;
        std::cout << "Enter contact index to display (0-7): ";
    }
    Display(Contacts_class[i].get_firstname(),
            Contacts_class[i].get_lastname(),
            Contacts_class[i].get_nickname(),
            Contacts_class[i].get_phonenumber(),
            Contacts_class[i].get_darksecret());
}