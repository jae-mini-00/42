#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        // ScalarConverter a;

        ScalarConverter::converter(av[1]);
    }
}