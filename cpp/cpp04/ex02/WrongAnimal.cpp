#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("None")
{
    std::cout   << COLOR_GREEN << "WrongAnimal default constructor called"  << COLOR_RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout   << COLOR_GREEN << "WrongAnimal constructor called" << COLOR_RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout   << COLOR_GREEN << "WrongAnimal copy constructor called" << COLOR_RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout   << COLOR_GREEN << "WrongAnimal copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << COLOR_BLUE << "WrongAnimal destructor called" << COLOR_RESET << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout   << COLOR_RED << "WrongAnimal~" << COLOR_RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}