#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    private :
        Brain *idea;
    public :
        Dog();
        Dog(std::string& name);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();
        
        void makeSound() const;
        void setBrainidea(std::string idea);
        const std::string* getBrainidea() const;
};

#endif