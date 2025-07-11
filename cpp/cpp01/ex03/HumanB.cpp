#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    weapon = NULL;
    std::cout   << name << " create!" << std::endl;
}

HumanB::~HumanB()
{
    std::cout   << name << " die" << std::endl;
}

void    HumanB::setWeapon(Weapon &type)
{
    weapon = &type;
    std::cout   << name << " have a weapon: " << weapon->getType() << std::endl;
}

void    HumanB::attack()
{
    if (weapon)
        std::cout   << name << " attacked with a " << weapon->getType() << std::endl;
}
