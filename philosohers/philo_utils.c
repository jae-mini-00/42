#include "philo.h"

unsigned int	ft_atoi(const char *str)
{
    int i = 0;
    int n = 0;

    while (str[i] >= 9 && (str[i] <= 13 || str[i] == ' '))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            return (0);
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        n = (n * 10) + (str[i] - '0');
        i++;
    }
    return (n);
}