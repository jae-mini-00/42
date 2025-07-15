#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(int data)
{
    value = data << this->fractional_bits;
}

Fixed::Fixed(float data)
{
    value = roundf(data * 256);
}

Fixed::Fixed(const Fixed& data)
{
    this->value = data.value;
}

Fixed::~Fixed()
{
  return ;
}

Fixed& Fixed::operator=(const Fixed& data)
{
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

Fixed Fixed::operator+(const Fixed& data) const
{
    Fixed temp(this->toFloat() + data.toFloat());
    return (temp);
}

Fixed Fixed::operator-(const Fixed& data) const
{
    Fixed temp(this->toFloat() - data.toFloat());
    return (temp);
}

Fixed Fixed::operator*(const Fixed& data) const
{
    Fixed temp(this->toFloat() * data.toFloat());
    return (temp);
}

Fixed Fixed::operator/(const Fixed& data) const
{
    Fixed temp(this->toFloat() / data.toFloat());
    return (temp);
}

Fixed& Fixed::operator++()
{
    this->value++;
    return (*this);
}

const Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->value++;
    return (temp);
}

Fixed& Fixed::operator--()
{
    this->value--;
    return (*this);
}

const Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->value--;
    return (temp);
}

bool Fixed::operator>(const Fixed& data) const
{
    return (this->toFloat() > data.toFloat() ? true : false);
}

bool Fixed::operator<(const Fixed& data) const
{
    return (this->toFloat() < data.toFloat() ? true : false);
}

bool Fixed::operator>=(const Fixed& data) const
{
    return (this->toFloat() >= data.toFloat() ? true : false);
}

bool Fixed::operator<=(const Fixed& data) const
{
    return (this->toFloat() <= data.toFloat() ? true : false);
}

bool Fixed::operator==(const Fixed& data) const
{
    return (this->toFloat() == data.toFloat() ? true : false);
}

bool Fixed::operator!=(const Fixed& data) const
{
    return (this->toFloat() != data.toFloat() ? true : false);
}

const Fixed Fixed::max(const Fixed& data1, const Fixed& data2)
{
    return (data1 > data2 ? data1 : data2);
}

const Fixed Fixed::min(const Fixed& data1, const Fixed& data2)
{
    return (data1 < data2 ? data1 : data2);
}

Fixed& Fixed::max(Fixed &data1, Fixed &data2)
{
    return (data1 > data2 ? data1 : data2);
}

Fixed& Fixed::min(Fixed &data1, Fixed &data2)
{
    return (data1 < data2 ? data1 : data2);
}