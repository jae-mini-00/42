#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Color.hpp"

class Animal
{
    protected :
        std::string type;
    private :

    public :
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        
        virtual void makeSound() const;
        std::string getType() const; 
};

#endif