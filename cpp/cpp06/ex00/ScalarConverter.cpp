#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

double ScalarConverter::Inf_or_Nan(std::string data, int mode) // mode = 1 = float, mode = 2 = double 
{
    if (data == "-inf")
    {
        if (mode == 1)
            return (-std::numeric_limits<float>::infinity());
        return (-std::numeric_limits<double>::infinity());
    }
    else if (data == "+inf")
    {
        if (mode == 1)
            return (std::numeric_limits<float>::infinity());
        return (std::numeric_limits<double>::infinity());
    }
    else if (data == "nan")
    {
        if (mode == 1)
            return (std::numeric_limits<float>::quiet_NaN());
        return (std::numeric_limits<double>::quiet_NaN());
    }
    return (0);
}

bool ScalarConverter::isChar(std::string str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && std::isprint(str[1]))
    {
        printChar(str[1], true, 0);
        return (true);
    }
    return (false);
}

bool ScalarConverter::isInt(std::string str)
{
    std::stringstream ss(str);
    long long num;

    ss >> num;
    if (ss.eof() && !ss.fail() && \
        num <= std::numeric_limits<int>::max() && \
        num >= std::numeric_limits<int>::min())
    {
        printChar(0, false, num);
        printInt(num, true, 0);
        return (true);
    }
    return (false);
}

bool ScalarConverter::isFloat(std::string str)
{
    if (str[str.length() - 1] == 'f')
    {
        std::string temp = str.substr(0, str.length() - 1);
        std::stringstream ss(temp);
        double num;

        ss >> num;
        if (((ss.eof() && !ss.fail()) || Inf_or_Nan(temp, 1)) && \
            num <= std::numeric_limits<float>::max() && \
            num >= -std::numeric_limits<float>::max())
        {
            if (!Inf_or_Nan(temp, 1))
            {
                printChar(0, false, num);
                printInt(0, false, num);
                printFloat(num, true, 0);
            }
            else
            {
                printChar(0, false, Inf_or_Nan(temp, 1));
                printInt(0, false, Inf_or_Nan(temp, 1));
                printFloat(Inf_or_Nan(temp, 1), true, 0);
            }
            return (true);
        }
    }
    return (false);
}

bool ScalarConverter::isDouble(std::string str)
{
    std::stringstream ss(str);
    double num;

    ss >> num;
    if (((ss.eof() && !ss.fail()) || Inf_or_Nan(str, 2)) && \
        num <= std::numeric_limits<double>::max() && \
        num >= -std::numeric_limits<double>::max())
    {
        if (!Inf_or_Nan(str, 2))
        {
            printChar(0, false, num);
            printInt(0, false, num);
            printFloat(0, false, num);
            std::cout   << "double: " << num << std::endl;
        }
        else
        {
            printChar(0, false, Inf_or_Nan(str, 2));
            printInt(0, false, Inf_or_Nan(str, 2));
            printFloat(0, false, Inf_or_Nan(str, 2));
            std::cout   << "double: " << Inf_or_Nan(str, 2) << std::endl;
        }
        return (true);
    }
    return (false);
}

void ScalarConverter::converter(std::string str)
{
    std::cout << std::fixed << std::setprecision(1);

    if (isChar(str))
        return ;
    else if (isInt(str))
        return ;
    else if (isFloat(str))
        return ;
    else if (isDouble(str))
        return ;
    else
        std::cout   << "Error: invalid argument" << std::endl;
}

void ScalarConverter::printChar(char c, bool flag, double num)
{
    if (!flag)
    {
        std::cout   << "char: ";
        if (num  > std::numeric_limits<char>::max() || \
            num < std::numeric_limits<char>::min() || std::isnan(num))
            std::cout   << "impossible" << std::endl;
        else if (!std::isprint(num))
            std::cout   << "Non displayable" << std::endl;
        else
            std::cout   << '\'' << static_cast<char>(num) << '\'' << std::endl;
        return ;
    }
    std::cout   << "char: '" << c << "'\n"
                << "int: "  << static_cast<int>(c) << '\n'
                << "float: " << static_cast<float>(c) << "f\n"
                << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printInt(int atoi, bool flag, double num)
{
    if (!flag)
    {
        std::cout   << "int: ";
        if (num  > std::numeric_limits<int>::max() || \
            num < std::numeric_limits<int>::min() || std::isnan(num))
            std::cout   << "impossible" << std::endl;
        else
            std::cout   << static_cast<int>(num) << std::endl;
        return ;
    }
    std::cout   << "int: "  << atoi << '\n'
                << "float: " << static_cast<float>(atoi) << "f\n"
                << "double: " << static_cast<double>(atoi) << std::endl;
}

void ScalarConverter::printFloat(float atof, bool flag, double num)
{
    if (!flag)
    {
        std::cout   << "float: ";
        if (num  > std::numeric_limits<float>::max() || \
            num < -std::numeric_limits<float>::max())
            std::cout   << "impossible" << std::endl;
        else
            std::cout   << static_cast<float>(num) << std::endl;
        return ;
    }
    std::cout   << "float: " << atof << "f\n"
                << "double: " << static_cast<double>(atof) << std::endl;
}