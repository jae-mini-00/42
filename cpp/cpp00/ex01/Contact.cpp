#include "Contact.hpp"

void    Contact::printf_contact(const char *meg, std::string data)
{
    std::cout << meg << ": " << data << std::endl;
}

std::string Contact::formatField(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void    Contact::main_display_print(int i)
{
    std::string num;

    num = i + 49;
    std::cout   << formatField("Index") << "|"
                << formatField("First Name") << "|"
                << formatField("Last Name") << "|"
                << formatField("Nickname") << std::endl;
    std::cout   << formatField(num) << "|"
                << formatField(first_name) << "|"
                << formatField(last_name) << "|"
                << formatField(nickname) << std::endl;
}

void    Contact::contact_display()
{
    printf_contact("First Name", first_name);
    printf_contact("Last Name", last_name);
    printf_contact("Nickname", nickname);
    printf_contact("Phone Number", phone_number);
    printf_contact("Darkest Secret", darkest_secret);
}

void    Contact::add_contact(void)
{
    first_name = getdata("First Name");
    last_name = getdata("Last Name");
    nickname = getdata("Nickname");
    phone_number = getdata("Phone Number");
    darkest_secret = getdata("Darkest Secret");
}

std::string    Contact::getdata(const char *meg)
{
    std::string data;

    while (!std::cin.eof())
    {
        std::cout << meg << ": "  << std::flush;
        std::getline(std::cin, data);
        if (std::cin.eof())
            break ;
        if (!data.empty())
            break ;
        std::cout << "Input cannot be empty. Please try again." << std::endl;
    }
    return (data);
}