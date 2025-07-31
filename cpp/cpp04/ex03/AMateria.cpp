#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : Type("Amateria")
{
    std::cout   << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) : Type(other.Type)
{
    std::cout   << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    std::cout   << "AMateria copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->Type = other.Type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout  << "AMateria destructor called"  << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->Type);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout  << "Need to overriding method"  << std::endl;
}