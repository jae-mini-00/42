#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include "Color.hpp"

class Brain
{
    private :
        std::string ideas[100];
    public:
        Brain();
        Brain(const std::string other[100]);
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
};

#endif