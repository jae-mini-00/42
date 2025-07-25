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
    std::cout   << "[ DEBUG ]" << std::endl;
    std::cout   << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
                << std::endl;
}

void    Harl::info(void)
{
    std::cout   << "[ INFO ]" << std::endl;
    std::cout   << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout   << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout   << "[ WARNING ]" << std::endl;
    std::cout   << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout   << "I've been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout   << "[ ERROR ]" << std::endl;
    std::cout   << "This is unacceptable! I want to speak to the manager now."
                << std::endl;
}

Level   Harl::string_to_level(std::string level)
{
    std::string temp[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    Level a_level[5] = {DEBUG, INFO, WARNING, ERROR, UNKNOWN};

    for (int i = 0; i < 4; i++)
    {
        if (temp[i] == level)
            return (a_level[i]);
    }
    return (a_level[5]);
}

void    Harl::complain(std::string level)
{
    Level level_case = Harl::string_to_level(level);
    switch (level_case)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break ;
        default:
            std::cout   << "[ Probably complaining about insignificant problems ]" 
                << std::endl;
            break;
    }
}
