#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl << std::endl;

    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl<< std::endl;

    std::cout <<  Fixed( 5.05f ) + Fixed( 5.05f )  << std::endl;
    std::cout <<  Fixed( 5.05f ) - Fixed( 5.05f )  << std::endl;
    std::cout <<  Fixed( 5.05f ) * Fixed( 2 )  << std::endl;
    std::cout <<  Fixed( 5.05f ) / Fixed( 5.05f )  << std::endl << std::endl;

    Fixed(5.05f) > Fixed(2) ? std::cout <<  "TRUE"  << std::endl : std::cout <<  "FLASE"  << std::endl;
    Fixed(5.05f) < Fixed(2) ? std::cout <<  "TRUE"  << std::endl : std::cout <<  "FLASE"  << std::endl;
    Fixed(5.05f) <= Fixed(5.05f) ? std::cout <<  "TRUE"  << std::endl : std::cout <<  "FLASE"  << std::endl;
    Fixed(5.05f) >= Fixed(10) ? std::cout <<  "TRUE"  << std::endl : std::cout <<  "FLASE"  << std::endl;
    Fixed(5.05f) == Fixed(5.05f) ? std::cout <<  "TRUE"  << std::endl : std::cout <<  "FLASE"  << std::endl;
    Fixed(5.05f) != Fixed(5.05f) ? std::cout <<  "TRUE\n"  << std::endl : std::cout <<  "FLASE\n"  << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    return 0;
}