#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cerr   << "Error: could not open file." << std::endl;
        return (1);
    }
    else if (ac == 2)
    {
        BitcoinExchange DB;
        if (!DB.makeDB("data.csv"))
            return (1);
        DB.buybit(av[1]);
        return(0);
    }
    else
    {
        std::cerr   << "Error: too many file." << std::endl;
        return (1);
    }
}