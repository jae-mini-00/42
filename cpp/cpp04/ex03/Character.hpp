#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private :
        AMateria *bag[4];
        std::string name;
    public :
        Character();
        Character(const std::string name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif