#include "Harl.hpp"

Harl::Harl()
{
    ;
}

Harl::~Harl()
{
    ;
}

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout   << "Fetching user data from API with user_id=12345"
                << std::endl;
}

void    Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout   << "User successfully logged in. user_id=12345"
                << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout   << "User profile image not found, using default avatar. user_id=12345"
                << std::endl;
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout   << "Failed to save user data to database. user_id=12345, error=ConnectionTimeout"
                << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void(Harl::*functions[4])(void) = 
    {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for(int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            (this->*functions[i])();
            return ;
        }
    }
    std::cout   << "Level not find" << std::endl;
}