#include "philo.h"

int	ft_atoi(const char *str)
{
    int i = 0;
    int n = 0;
    int sign = 1;

    while (str[i] >= 9 && (str[i] <= 13 || str[i] == ' '))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9' && str[i])
    {
        n = (n * 10) + (str[i] - '0');
        i++;
    }
    return (n * sign);
}