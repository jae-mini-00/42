#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

class Harl
{
    private :
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        Level   string_to_level(std::string level);
    public :
        Harl();
        ~Harl();
        void    complain(std::string level);
};

#endif