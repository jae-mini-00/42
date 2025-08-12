#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include <iostream>

class ScalarConverter
{
    private :
        static bool isChar(std::string str);
        static bool isInt(std::string str);
        static bool isFloat(std::string str);
        static bool isDouble(std::string str);
        static void printChar(char c, bool flag, double num);
        static void printInt(int atoi, bool flag, double num);
        static void printFloat(float atof, bool flag, double num);

        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
    public :
        static void converter(std::string str);

};

#endif