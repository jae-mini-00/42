#include "Animal.hpp"

Animal::Animal() : type("None")
{
    std::cout   << COLOR_GREEN << "Animal default constructor called"  << COLOR_RESET << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout   << COLOR_GREEN << "Animal constructor called" << COLOR_RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout   << COLOR_GREEN << "Animal copy constructor called" << COLOR_RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout   << COLOR_GREEN << "Animal copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Animal::~Animal()
{
    std::cout << COLOR_BLUE << "Animal destructor called" << COLOR_RESET << std::endl;
}

void Animal::makeSound() const
{
    std::cout   << COLOR_RED << "Animal~" << COLOR_RESET << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}