#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("jaejo");
    ScavTrap b;
    ScavTrap c = ScavTrap("A");

    b = c;
    for (int i = 0; i < 50; i++)
        a.beRepaired(10);
    for (int i = 0; i < 50; i++)
    {
        b.attack("jaejo");
        a.takeDamage(0);
    }
    a.attack("jaejo");
    a.beRepaired(10);
    b.attack("A");
    b.beRepaired(10);
    a.guardGate();
    b.guardGate();
    return (0);
}