#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    i = 0;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void    PhoneBook::ft_add()
{
    if (i == 8)
        i = 0;
    list[i].add_contact();
    i++;
}

void    PhoneBook::main_display()
{
    int i = 0;

    while (i < 8)
    {
        list[i].main_display_print(i);
        i++;
    }
}

void    PhoneBook::ft_search()
{
    int         num = 0;

    main_display();
    std::cout << "SEARCh Number: " << std::flush;
    std::cin >> num;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    else if (num <= 0 || num > 8)
        std::cout << "the index is out of range or wrong(1 ~ 8)" << std::endl;
    else
        list[num - 1].contact_display();
    std::cin.ignore();
}
