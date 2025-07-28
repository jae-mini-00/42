#include <iostream>
#include "Color.hpp"
#include "Brain.hpp"

Brain::Brain()
{
    std::cout   << COLOR_GREEN << "Brain default constructor called"  << COLOR_RESET << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Nothing";
}

Brain::Brain(const std::string other[100])
{
    std::cout   << COLOR_GREEN << "Brain constructor called" << COLOR_RESET << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other[i];
}

Brain::Brain(const Brain& other)
{
    std::cout   << COLOR_GREEN << "Brain copy constructor called" << COLOR_RESET << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout   << COLOR_GREEN << "Brain copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << COLOR_BLUE << "Brain destructor called" << COLOR_RESET << std::endl;
}

void Brain::setBrain(std::string str)
{
    for(int i = 0; i < 100; i++)
        ideas[i] = str;
}

const std::string* Brain::getBrain() const
{
    return (this->ideas);
}
