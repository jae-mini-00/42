#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>

class ScalarConverter
{
    private :
        static void isChar(std::string str);
        static void isInt(std::string str);
        // static void isFloat(std::string str);
        // static void isDouble(std::string str);

        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public :
        static void converter(std::string str);

};

#endif