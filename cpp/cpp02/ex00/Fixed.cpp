#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout   << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& data)
{
    std::cout   << "Copy constructor called" << std::endl;
    this->value = data.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& data)
{
    if (this != &data)
    {
        this->value = data.value;
        std::cout   << "Copy assignment operator called" << std::endl;
    }
    return (*this);
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout   << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
