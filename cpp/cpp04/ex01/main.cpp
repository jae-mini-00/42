#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ClapTrap b("jaejo");
    ClapTrap c(a);
    ClapTrap d;

    d = b;
    for (int i = 0; i < 10; i++)
        a.beRepaired(10);
    for (int i = 0; i < 10; i++)
    {
        b.attack("A");
        a.takeDamage(0);
    }
    a.attack("jaejo");
    a.beRepaired(10);
    b.attack("A");
    b.beRepaired(10);
    return (0);
}