#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout   << "Default constructor called" << std::endl;
}

Fixed::Fixed(int data)
{
    std::cout   << "Int constructor called" << std::endl;
    value = data << this->fractional_bits;
}

Fixed::Fixed(float data)
{
    std::cout   << "Float constructor called" << std::endl;
    value = roundf(data * 256);
}

Fixed::Fixed(const Fixed& data)
{
    std::cout   << "Copy constructor called" << std::endl;
    *this = data;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& data)
{
    std::cout   << "Copy assignment operator called" << std::endl;
    if (this != &data)
    {
        this->value = data.getRawBits();
    }
    return (*this);
}

float Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::toInt( void ) const
{
    return (value >> fractional_bits);
}

float Fixed::toFloat( void ) const
{
    return ((float)value / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed &data)
{
    os   << data.toFloat();
    return (os);
}
