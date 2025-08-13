#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::converter(av[1]);
    }
}