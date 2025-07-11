#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return (NULL);
    Zombie *Horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        Horde[i].Setname(name);
        Horde[i].announce();
    }
    return (Horde);
}