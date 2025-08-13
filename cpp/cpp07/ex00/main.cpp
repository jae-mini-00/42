#include <iostream>
#include <iomanip>
#include "whatever.hpp"

int main(void)
{
    {
        int a = 2;
        int b = 3;

        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1);
    {
        char a = 'a';
        char b = 'b';
        char c[2] = {'c', '\0'};
        char d[2] = {'d', '\0'};
        char &e = a;
        char &f = b;
        std::cout << "========char test======" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "swap( a, b )" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << std::endl;

        std::cout << "c = " << c << ", d = " << d << std::endl;
        ::swap(*c, *d);
        std::cout << "swap( c, d )" << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::cout << std::endl;

        std::cout << "e = " << e << ", f = " << f << std::endl;
        ::swap(e, f);
        std::cout << "swap( e, f )" << std::endl;
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
        std::cout << std::endl;
    }

    {
        int a = 'a';
        int b = 'b';
        int *c = &a;
        int *d = &b;
        int &e = a;
        int &f = b;
        std::cout << "========const int test======" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "swap( a, b )" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << std::endl;

        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        ::swap( c, d );
        std::cout << "swap( c, d )" << std::endl;
        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        std::cout << "min( c, d ) = " << *::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << *::max( c, d ) << std::endl;
        std::cout << std::endl;

        std::cout << "e = " << e << ", f = " << f << std::endl;
        ::swap( e, f );
        std::cout << "swap( e, f )" << std::endl;
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
        std::cout << std::endl;
    }

    {
        long a = 'a';
        long b = 'b';
        long *c = &a;
        long *d = &b;
        long &e = a;
        long &f = b;
        std::cout << "========const long test======" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "swap( a, b )" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << std::endl;

        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        ::swap( c, d );
        std::cout << "swap( c, d )" << std::endl;
        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        std::cout << "min( c, d ) = " << *::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << *::max( c, d ) << std::endl;
        std::cout << std::endl;

        std::cout << "e = " << e << ", f = " << f << std::endl;
        ::swap( e, f );
        std::cout << "swap( e, f )" << std::endl;
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
        std::cout << std::endl;
    }

    {
        float a = 'a';
        float b = 'b';
        float *c = &a;
        float *d = &b;
        float &e = a;
        float &f = b;
        std::cout << "========const float test======" << std::endl;
        std::cout << "a = " << a << 'f' << ", b = " << b << 'f' << std::endl;
        ::swap( a, b );
        std::cout << "swap( a, b )" << std::endl;
        std::cout << "a = " << a << 'f' << ", b = " << b << 'f' << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << 'f' << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << 'f' << std::endl;
        std::cout << std::endl;

        std::cout << "c = " << *c << 'f' << ", d = " << *d << 'f' << std::endl;
        ::swap( c, d );
        std::cout << "swap( c, d )" << std::endl;
        std::cout << "c = " << *c << 'f' << ", d = " << *d << 'f' << std::endl;
        std::cout << "min( c, d ) = " << *::min( c, d ) << 'f' << std::endl;
        std::cout << "max( c, d ) = " << *::max( c, d ) << 'f' << std::endl;
        std::cout << std::endl;

        std::cout << "e = " << e << 'f' << ", f = " << f << 'f' << std::endl;
        ::swap( e, f );
        std::cout << "swap( e, f )" << std::endl;
        std::cout << "e = " << e << 'f' << ", f = " << f << 'f' << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << 'f' << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << 'f' << std::endl;
        std::cout << std::endl;
    }

    {
        double a = 'a';
        double b = 'b';
        double *c = &a;
        double *d = &b;
        double &e = a;
        double &f = b;
        std::cout << "========const double test======" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "swap( a, b )" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << std::endl;

        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        ::swap( c, d );
        std::cout << "swap( c, d )" << std::endl;
        std::cout << "c = " << *c << ", d = " << *d << std::endl;
        std::cout << "min( c, d ) = " << *::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << *::max( c, d ) << std::endl;
        std::cout << std::endl;

        std::cout << "e = " << e << ", f = " << f << std::endl;
        ::swap( e, f );
        std::cout << "swap( e, f )" << std::endl;
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
        std::cout << std::endl;
    }
    return 0;
}