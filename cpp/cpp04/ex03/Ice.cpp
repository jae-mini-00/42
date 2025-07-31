#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria()
{
    std::cout   << "Ice default constructor called" << std::endl;
    Type = "Ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    std::cout   << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    std::cout   << "Ice copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Type = other.Type;
    }
    return (*this);
}

Ice::~Ice()
{
    std::cout  << "Ice destructor called"  << std::endl;
}

AMateria* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout  << "* shoots an ice bolt at " << target.getName() << " *"  << std::endl;
}
