#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal(), idea(new Brain)
{
    std::cout   << COLOR_GREEN << "Cat default constructor called" << COLOR_RESET << std::endl;
    type = "Cat";
}

Cat::Cat(std::string& type) : Animal(type), idea(new Brain)
{
    std::cout   << COLOR_GREEN << "Cat constructor called" << COLOR_RESET << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other), idea(new Brain(*other.idea))
{
    std::cout   << COLOR_GREEN << "Cat copy constructor called" << COLOR_RESET << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout   << COLOR_GREEN << "Cat copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        delete this->idea;
        this->idea = new Brain(*other.idea);
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << COLOR_BLUE << "Cat destructor called" << COLOR_RESET << std::endl;
    delete this->idea;
}

void Cat::makeSound() const
{
    std::cout   << COLOR_RED << "Cat :Mewoooooooooooooo" << COLOR_RESET << std::endl;
}

void Cat::setBrainidea(std::string idea)
{
    this->idea->setBrain(idea);
}

const std::string* Cat::getBrainidea() const
{
    return (idea->getBrain());
}