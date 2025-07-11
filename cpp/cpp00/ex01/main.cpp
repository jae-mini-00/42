#include "PhoneBook.hpp"

int main()
{
    PhoneBook   data;
    std::string prompt;

    while (!std::cin.eof())
    {
        std::cout << "Phone Book: " << std::flush;
        std::getline(std::cin, prompt);
        if (prompt == "SEARCH")
            data.ft_search();
        else if (prompt == "ADD")
            data.ft_add();
        else if (prompt == "EXIT")
            break ;
        else
            std::cout << "Command Only \"ADD\", \"SEARCH\", \"EXIT\"" << std::endl;
    }
    return (0);
}