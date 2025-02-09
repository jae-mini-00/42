#include "philo.h"

unsigned int ft_atoi(const char *str)
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

void *int_memset(int *fork, int size)
{
    int i;

    i = -1;
    if (!fork)
        return (NULL);
    while (++i < size)
        fork[i] = 1;
    return (fork);
}

int parse_data(t_philo *data)
{
    int flag;

    flag = 0;
    if (!data->count_philo)
        flag = 1;
    else if (!data->time_to_die)
        flag = 1;
    else if (!data->time_to_eat)
        flag = 1;
    else if (!data->time_to_sleep)
        flag = 1;
    else if (data->eat_flag)
    {
        if (!data->least_eat)
            flag = 1;
    }
    return (flag);
}