#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    className = "FragTrap"; 
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout   << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    className = "FragTrap";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout   << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    this->className = "FragTrap";
    std::cout   << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout   << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit_points = other.hit_points;
        this->energy_points = other.energy_points;
        this->attack_damage = other.attack_damage;
    }
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << name << " FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->energy_points && this->hit_points)
    {
        this->energy_points--;
        std::cout   << "FragTrap " << name << " attacks " << target << ", causing " 
                    << attack_damage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout   << "FragTrap " << name << " cannot attack because ";
        if (!this->hit_points)
            std::cout   << name << "it has no hit points left." << std::endl;
        else
            std::cout   << name << "it has no energy points left." << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout   << "FragTrap " << name << " highFives!" << std::endl;
}
