#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->Type = type;
    std::cout   << "Weapon \"" << type << "\" create!" << std::endl;
    return ;
}

Weapon::~Weapon()
{
    std::cout   << "Weapon \"" << this->Type << "\" broke!" << std::endl;
    return ;
}

std::string &Weapon::getType()
{
    return (Type);
}

void    Weapon::setType(std::string type)
{
    this->Type = type;
    std::cout   << "Weapon change: " << type << std::endl;
    return ;
}
