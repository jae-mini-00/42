#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << '\n' << COLOR_YELLOW << meta->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << COLOR_RESET << '\n' << std::endl;;
    meta->makeSound();
    j->makeSound();
    i->makeSound();
    std::cout << std::endl;

    delete i;
    delete j;
    delete meta;
    std::cout << std::endl;

    {
        const Animal meta2 = Animal();
        const Animal j2 = Dog();
        const Animal i2 = Cat();

        std::cout << '\n' << COLOR_YELLOW << meta2.getType() << " " << std::endl;
        std::cout << j2.getType() << " " << std::endl;
        std::cout << i2.getType() << " " << COLOR_RESET << '\n' << std::endl;;
        meta2.makeSound();
        j2.makeSound();
        i2.makeSound();
        std::cout << std::endl;
    }

    std::cout << std::endl;
    const WrongAnimal* Wronganimal = new WrongAnimal();
    const WrongAnimal* Wrongcat = new WrongCat();

    std::cout << '\n' << COLOR_YELLOW << Wronganimal->getType() << " " << std::endl;
    std::cout << Wrongcat->getType() << " " << COLOR_RESET << '\n' << std::endl;;
    Wronganimal->makeSound();
    Wrongcat->makeSound();
    std::cout << std::endl;

    delete Wrongcat;
    delete Wronganimal;
    std::cout << std::endl;

    const WrongAnimal Wronganimal2;
    const WrongAnimal Wrongcat2 = WrongCat();

    std::cout << '\n' << COLOR_YELLOW << Wronganimal2.getType() << " " << std::endl;
    std::cout << Wrongcat2.getType() << " " << COLOR_RESET << '\n' << std::endl;;
    Wronganimal2.makeSound();
    Wrongcat2.makeSound();
    std::cout << std::endl;

    return 0;
}