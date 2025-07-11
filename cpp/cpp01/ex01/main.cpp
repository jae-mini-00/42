#include "./Zombie.hpp"

int main(void)
{
    Zombie c("Stack1");
    Zombie *a = zombieHorde(5, "heap");

    if (!a)
        return (1);
    c.announce();
    delete []a;
    return (0);
}