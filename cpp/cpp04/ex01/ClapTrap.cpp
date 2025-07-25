#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NoName")
{
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout   << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name)
{
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
    std::cout   << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name),
                                            hit_points(other.hit_points),
                                            energy_points(other.energy_points),
                                            attack_damage(other.attack_damage)
{
    std::cout   << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout   << "ClapTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
  std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_points && this->hit_points)
    {
        this->energy_points--;
        std::cout   << "ClapTrap " << name << " attacks " << target << ", causing " 
                    << attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap " << name << " cannot attack because ";
        if (!this->hit_points)
            std::cout   << name << "it has no hit points left." << std::endl;
        else
            std::cout   << name << "it has no energy points left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout   << "ClapTrap " << name << " takes " << amount << " points of damage! -> ";
    if (this->hit_points > amount)
    {
        this->hit_points -= amount;
        std::cout   << name << " total hit point: " << this->hit_points << std::endl;
    }
    else
    {
        this->hit_points = 0;
        std::cout   << name << " destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_points && this->hit_points)
    {
        this->hit_points += amount;
        this->energy_points--;
        std::cout   << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit point! -> " 
                    << name << " total hit point: " << this->hit_points << std::endl;
    }
    else
    {
        std::cout   << "ClapTrap " << name << " cannot repair itself because ";
        if (!this->hit_points)
            std::cout   << name << " it has no hit points left." << std::endl;
        else
            std::cout   << name << " it has no energy points left." << std::endl;
    }
}
