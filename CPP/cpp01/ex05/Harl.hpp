#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private :
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        std::string level;
    public :
        Harl(std::string level);
        ~Harl();
        void    complain(std::string level);
};

#endif