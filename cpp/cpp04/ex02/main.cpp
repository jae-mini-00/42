#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *array[4];
    for (int i = 0; i < 2; i++)
        array[i] = new Cat();
    for (int i = 2; i < 4; i++)
        array[i] = new Dog();
    std::cout    << std::endl;
    
    for (int i = 0; i < 4; i++)
        delete array[i];
    std::cout    << std::endl;

    std::cout   <<"================== Copy ======================" << std::endl;
    Cat *cat = new Cat();
    cat->setBrainidea("fish");
    const std::string *brain = cat->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain[i] << std::endl;
    std::cout    << std::endl;

    Cat *copy_cat = new Cat();
    *copy_cat = *cat;
    brain = copy_cat->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain[i] << std::endl;
    std::cout    << std::endl;

    std::cout   <<"================== Copy TEST ======================" << std::endl;
    copy_cat->setBrainidea("sleep");
    brain = cat->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain[i] << std::endl;
    std::cout    << std::endl;

    brain = copy_cat->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain[i] << std::endl;
    std::cout    << std::endl;
    
    delete copy_cat;
    delete cat;
    std::cout   <<"================== operator ======================" << std::endl;
    Cat *cat2 = new Cat();
    cat2->setBrainidea("fish");
    const std::string *brain2 = cat->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain2[i] << std::endl;
    std::cout    << std::endl;

    Cat *copy_cat2 = cat2;
    brain2 = copy_cat2->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain2[i] << std::endl;
    std::cout    << std::endl;
    std::cout   <<"================== operator test ======================" << std::endl;
    cat2->setBrainidea("sleep");
    brain2 = cat2->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain2[i] << std::endl;
    std::cout    << std::endl;

    brain2 = copy_cat2->getBrainidea();
    for (int i = 0; i < 100; i++)
        std::cout   << brain2[i] << std::endl;
    std::cout    << std::endl;

    delete cat2;
}