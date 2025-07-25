#include "FragTrap.hpp"

int main(void)
{
    FragTrap a("jaejo");
    FragTrap b;
    FragTrap c = FragTrap("A");

    b = c;
    for (int i = 0; i < 100; i++)
        a.beRepaired(10);
    for (int i = 0; i < 100; i++)
    {
        b.attack("jaejo");
        a.takeDamage(0);
    }
    a.attack("jaejo");
    a.beRepaired(10);
    b.attack("A");
    b.beRepaired(10);
    a.highFivesGuys();
    b.highFivesGuys();
    return (0);
}