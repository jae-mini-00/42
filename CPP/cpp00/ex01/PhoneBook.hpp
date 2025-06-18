#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook
{
    public :
        static int i;
        Contact List[8];
        PhoneBook()
        {
            i = 0;
        }
        ~PhoneBook()
        {
            return ;
        }
        void    ft_add()
        {
            if (i == 8)
                i = 0;
            List[i].add_contact();
            i++;
        }
        void    ft_serch()
        {
            std::cout << "SERCh Number: " << std::flush;
            std::cin >> num;
            if (std::cin.fail() || std::cin.eof())
            {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (num <= 0 || num > 8)
                std::cout << "the index is out of range or wrong(1 ~ 8)" << std::endl;
            else
                List[num - 1].display();
        }
    private :
        int     num;

};

#endif