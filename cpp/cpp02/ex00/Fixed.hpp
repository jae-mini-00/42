#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int value;
        static const int fractional_bits;
    public :
        Fixed();
        Fixed(const Fixed&);
        Fixed& operator=(const Fixed&);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif