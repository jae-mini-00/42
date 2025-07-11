#include <iostream>

int main(int ac, char **av)
{
    int i = 1;
    if (ac == i)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (ac > i)
    {
        for (int j = 0; av[i][j] != '\0'; j++)
            av[i][j] = std::toupper(av[i][j]);
        std::cout << av[i++];
    }
    std::cout << "\n";
    return (0); 
}