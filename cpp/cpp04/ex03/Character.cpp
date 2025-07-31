#include "Character.hpp"
#include <iostream>

Character::Character() : name("NoName")
{
    std::cout   << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        bag[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    std::cout   << "Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        bag[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
    std::cout   << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        bag[i] = other.bag[i];
}

Character& Character::operator=(const Character& other)
{
    std::cout   << "Character copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++)
            bag[i] = other.bag[i];
    }
    return (*this);
}

Character::~Character()
{
    std::cout  << "Character destructor called"  << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete bag[i];
        bag[i] = NULL;
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!bag[i])
        {
            bag[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > -1 && idx < 4 && bag[idx])
        bag[idx] = NULL;
    else
        std::cout   << "Impossible unequip idx" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > -1 && idx < 4 && bag[idx])
        bag[idx]->use(target);
    else
        std::cout   << "Impossible use idx" << std::endl;
}