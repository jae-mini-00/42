#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : weapon(type)
{
    this->name = name;
    std::cout   << name << " create!" << std::endl;
}

HumanA::~HumanA()
{
    std::cout   << name << " die" << std::endl;
}

void    HumanA::setWeapon(Weapon& type)
{
    weapon = type.getType();
    std::cout   << name << " have a weapon: " << weapon.getType() << std::endl;
}

void    HumanA::attack()
{
    std::cout   << name << " attacked with a " << weapon.getType() << std::endl;
}