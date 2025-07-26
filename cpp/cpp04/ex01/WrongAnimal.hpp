#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include "Color.hpp"
#include "Brain.hpp"

class WrongAnimal
{
    protected :
        std::string type;
    private :

    public :
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal& other);
        WrongAnimal& operator=(const WrongAnimal& other);
        virtual ~WrongAnimal();
        
        void makeSound() const;
        std::string getType() const; 
};

#endif