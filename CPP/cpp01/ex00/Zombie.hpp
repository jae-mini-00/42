#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public :
        std::string name;
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
    private :
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif