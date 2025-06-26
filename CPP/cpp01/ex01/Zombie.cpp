#include "./Zombie.hpp"

Zombie::Zombie(void)
{
    std::cout   << "Zombie Horde create!" << std::endl;
    return ;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout   << "Zombie " << name << " create!" << std::endl;
}

Zombie::~Zombie()
{
    std::cout   << "Zombie " << name
                << " destroyed!"
                << std::endl;
}

void Zombie::announce( void )
{
    std::cout   << name << ": "
                << "BraiiiiiiinnnzzzZ..."
                << std::endl;
}

void Zombie::Setname(std::string name)
{
    this->name = name;
}
