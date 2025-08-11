#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) 
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::isChar(std::string str)
{
    char c = str[0];

    std::cout   << "char: '" << c << "'\n"
                << "int: "  << static_cast<int>(c) << '\n'
                << "float: " << static_cast<float>(c) << "f\n"
                << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::isInt(std::string str)
{
    std::stringstream ss(str);
    int num;

    ss >> num;
    if (ss.fail() || !ss.eof())
        std::cout   << "int: impossible" << std::endl;
    else
    {
        std::cout   << "char: '" << static_cast<char>(num) << "'\n"
                    << "int: "  << num << '\n'
                    << "float: " << static_cast<float>(num) << "f\n"
                    << "double: " << static_cast<double>(num) << std::endl;
    }
}

void ScalarConverter::converter(std::string str)
{
    std::cout << std::fixed << std::setprecision(1);
    if (str.length() < 2)
        isChar(str);
    else if (str.length() < 11 || (str[0] == '-' && str.length() < 12))
        isInt(str);
    // this->isFloat(str);
    // this->isDouble(str);
}