#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    std::cout   << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        save[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout   << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        save[i] = (other.save[i] ? other.save[i]->clone() : NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout   << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete save[i];
            save[i] = (other.save[i] ? other.save[i]->clone() : NULL);
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout  << "MateriaSource destructor called"  << std::endl;
    for (int i = 0; i < 4; i++)
    {
        delete save[i];
        save[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* other)
{
    if (!other)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!save[i])
        {
            save[i] = other->clone();
            delete other;
            return ;
        }
    }
    delete other;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (save[i] && save[i]->getType() == type)
            return (save[i]->clone());
    }
    return (NULL);
}