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
        void    printf_display(const char *meg, char *data)
        {
            if (data)
            {
                if (strlen(data) < 10)
                    std::cout << "|" << meg << ": " << data;
                else
                {
                    std::cout << "|" << meg << ": ";
                    for (int i = 0; i < 10; i++)
                        std::cout << data[i]; 
                    std::cout << ".";
                }
            }
            else
                std::cout << "|" << meg << ": ";
        }
        void    display()
        {
            printf_display("First Name", FirstName);
            printf_display("Last Name", LastName);
            printf_display("Nickname", Nickname);
            printf_display("Phone Number", PhoneNumber);
            printf_display("Darkest Secret", DarkestSecret);
            std::cout << "|" << std::endl;
        }
        char    *getdata(const char *meg)
        {
            char *data = new char[100];

            data[0] = '\0';
            while (true)
            {
                std::cout << meg << ": "  << std::flush;
                if (std::cin.peek() == '\n')
                    std::cin.ignore();
                std::cin.getline(data, 100);
                if (data[0])
                    break ;
                std::cout << "Input cannot be empty. Please try again." << std::endl;
            }
            return (data);
        }
        void    add_contact(void)
        {
            FirstName = getdata("First Name");
            LastName = getdata("Last Name");
            Nickname = getdata("Nickname");
            PhoneNumber = getdata("Phone Number");
            DarkestSecret = getdata("Darkest Secret");
        }
        Contact()
        {
            FirstName = NULL;
            LastName = NULL;
            Nickname = NULL;
            PhoneNumber = NULL;
            DarkestSecret = NULL;
        }
        ~Contact()
        {
            delete[] FirstName;
            delete[] LastName;
            delete[] Nickname;
            delete[] PhoneNumber;
            delete[] DarkestSecret;
        }
    private :
        char *FirstName;
        char *LastName;
        char *Nickname;
        char *PhoneNumber;
        char *DarkestSecret;
};

#endif