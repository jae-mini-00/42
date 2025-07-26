#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout   << COLOR_GREEN << "Dog default constructor called" << COLOR_RESET << std::endl;
}

Dog::Dog(std::string& type) : Animal(type)
{
    type = "Dog";
    std::cout   << COLOR_GREEN << "Dog constructor called" << COLOR_RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    std::cout   << COLOR_GREEN << "Dog copy constructor called" << COLOR_RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout   << COLOR_GREEN << "Dog copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << COLOR_BLUE << "Dog destructor called" << COLOR_RESET << std::endl;
}

void Dog::makeSound() const
{
    std::cout   << COLOR_RED << "DOG :BarkKKKKKKKKKKKKKKKKKKKKKK" << COLOR_RESET << std::endl;
}
