#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./Contact.hpp"

class PhoneBook
{
    public :
        PhoneBook();
        ~PhoneBook();
        void    ft_add();
        void    main_display();
        void    ft_search();
    private :
        int i;
        Contact list[8];
};

#endif