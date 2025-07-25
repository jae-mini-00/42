#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("A");
    std::cout   << "\n" << std::endl;
    FragTrap b("B");
    std::cout   << "\n" << std::endl;
    ScavTrap c("C");
    std::cout   << "\n" << std::endl;
    ClapTrap d("D");
    std::cout   << "\n" << std::endl;

    a.whoAmI();
    a.guardGate();
    a.highFivesGuys();
    a.attack("B");
    for (int i = 0; i < 50; i++)
        a.beRepaired(10);
    a.attack("B");
    std::cout   << "\n" << std::endl;
    return (0);
}