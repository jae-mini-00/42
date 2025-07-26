#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout   << COLOR_GREEN << "WrongCat default constructor called" << COLOR_RESET << std::endl;
}

WrongCat::WrongCat(std::string& type) : WrongAnimal(type)
{
    type = "WrongCat";
    std::cout   << COLOR_GREEN << "WrongCat constructor called" << COLOR_RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    std::cout   << COLOR_GREEN << "WrongCat copy constructor called" << COLOR_RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout   << COLOR_GREEN << "WrongCat copy assignment operator called" << COLOR_RESET << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << COLOR_BLUE << "WrongCat destructor called" << COLOR_RESET << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout   << COLOR_RED << "WrongCat :Mewoooooooooooooo" << COLOR_RESET << std::endl;
}
