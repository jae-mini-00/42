#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <cstdio>

class Contact
{
    public :
        void    main_display_print(int i);
        void    contact_display();
        void    add_contact(void);
        void    printf_contact(const char *meg, std::string data);
    private :
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        std::string getdata(const char *meg);
        std::string formatField(const std::string& str);
};

#endif