#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int value;
        static const int fractional_bits = 8;
    public :
        Fixed();
        Fixed(int data);
        Fixed(float data);
        Fixed(const Fixed& data);
        Fixed& operator=(const Fixed&);
        ~Fixed();
        float getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt( void ) const;
        float toFloat( void ) const;
        Fixed operator+(const Fixed& data) const;
        Fixed operator-(const Fixed& data) const;
        Fixed operator*(const Fixed& data) const;
        Fixed operator/(const Fixed& data) const;
        Fixed& operator++();
        const Fixed operator++(int data);
        Fixed& operator--();
        const Fixed operator--(int data);
        bool operator>(const Fixed& data) const;
        bool operator<(const Fixed& data) const;
        bool operator>=(const Fixed& data) const;
        bool operator<=(const Fixed& data) const;
        bool operator==(const Fixed& data) const;
        bool operator!=(const Fixed& data) const;
        static const Fixed max(const Fixed& data1, const Fixed& data2);
        static const Fixed min(const Fixed& data1, const Fixed& data2);
        Fixed& max(Fixed &data1, Fixed &data2);
        Fixed& min(Fixed &data1, Fixed &data2);
};

std::ostream& operator<<(std::ostream& os, const Fixed &data);

#endif