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
        Fixed(const Fixed&);
        Fixed& operator=(const Fixed&);
        ~Fixed();
        float getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt( void ) const;
        float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &data);

#endif