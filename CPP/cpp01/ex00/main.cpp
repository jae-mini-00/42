#include "./Zombie.hpp"

int main(void)
{
    Zombie c("Stack1");
    Zombie *a = newZombie("heap");
    randomChump("Stack2");

    c.announce();
    a->announce();
    delete a;
    return (0);
}