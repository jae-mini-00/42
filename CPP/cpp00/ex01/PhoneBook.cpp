#include "PhoneBook.hpp"
#include <cstdio>
#include <unistd.h>


int PhoneBook::i = 0;

int main()
{
    PhoneBook   data;
    char        *prompt = new char[100];

    while (true)
    {
        std::cout << "Phone Book: " << std::flush;
        if (std::cin.peek() == '\n')
            std::cin.ignore();
        if (!std::cin.getline(prompt, 100))
        {
            std::cout << "Command Only \"ADD\", \"SERCH\", \"EXIT\"" << std::endl;
            std::cin.clear();
            continue ;
        }
        else if (!strcmp(prompt, "SERCH"))
            data.ft_serch();
        else if (!strcmp(prompt, "ADD"))
            data.ft_add();
        else if (!strcmp(prompt, "EXIT"))
            break ;
        else
            std::cout << "Command Only \"ADD\", \"SERCH\", \"EXIT\"" << std::endl;
    }
    delete[] prompt;
    return (0);
}