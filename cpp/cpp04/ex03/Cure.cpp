#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria()
{
    std::cout   << "Cure default constructor called" << std::endl;
    Type = "Cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    std::cout   << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout   << "Ice copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Type = other.Type;
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout  << "Ice destructor called"  << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout  << "* heals " << target.getName() << "\'s wounds *"  << std::endl;
}