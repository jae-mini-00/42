#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal(), idea(new Brain)
{
    std::cout   << COLOR_GREEN << "Dog default constructor called" << COLOR_RESET << std::endl;
    type = "Dog";
}

Dog::Dog(std::string& type) : Animal(type), idea(new Brain)
{
    std::cout   << COLOR_GREEN << "Dog constructor called" << COLOR_RESET << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), idea(new Brain(*other.idea))
{
    std::cout   << COLOR_GREEN << "Dog copy constructor called" << COLOR_RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout   << COLOR_GREEN << "Dog copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        delete this->idea;
        this->idea = new Brain(*other.idea);
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << COLOR_BLUE << "Dog destructor called" << COLOR_RESET << std::endl;
    delete this->idea;
}

void Dog::makeSound() const
{
    std::cout   << COLOR_RED << "DOG :BarkKKKKKKKKKKKKKKKKKKKKKK" << COLOR_RESET << std::endl;
}
