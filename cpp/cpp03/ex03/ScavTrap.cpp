#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    className = "ScavTrap";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout   << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    className = "ScavTrap";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout   << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout   << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout   << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << name << " ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_points && this->hit_points)
    {
        this->energy_points--;
        std::cout   << "ScavTrap " << name << " attacks " << target << ", causing " 
                    << attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout   << "ScavTrap " << name << " cannot attack because ";
        if (!this->hit_points)
            std::cout   << name << "it has no hit points left." << std::endl;
        else
            std::cout   << name << "it has no energy points left." << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout   << "ScavTrap " << name << " turn on guardGate!" << std::endl;
}
