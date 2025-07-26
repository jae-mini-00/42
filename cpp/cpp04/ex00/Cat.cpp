#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout   << COLOR_GREEN << "Cat default constructor called" << COLOR_RESET << std::endl;
}

Cat::Cat(std::string& type) : Animal(type)
{
    type = "Cat";
    std::cout   << COLOR_GREEN << "Cat constructor called" << COLOR_RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout   << COLOR_GREEN << "Cat copy constructor called" << COLOR_RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout   << COLOR_GREEN << "Cat copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << COLOR_BLUE << "Cat destructor called" << COLOR_RESET << std::endl;
}

void Cat::makeSound() const
{
    std::cout   << COLOR_RED << "Cat :Mewoooooooooooooo" << COLOR_RESET << std::endl;
}
