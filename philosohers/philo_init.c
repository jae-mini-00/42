
#include "philo.h"

void *philo_init(t_philo *data, int ac, char **av)
{
    if (ac < 5)
        return ("1");
    data->die_flag = 0;
    data->count_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
    {
        data->least_eat = ft_atoi(av[5]);
        data->eat_flag = 1;
    }
    else
        data->eat_flag = 0;
    if (parse_data(data))
        return ("1");
    return (0);
    //pthread_mutex_init(&data->mutex, NULL);
}

void *philo_brain_init(t_philo *data)
{
    int i;

    i = 0;
    data->fork = (int *)malloc(sizeof(int) * data->count_philo);
    data->fork = int_memset(data->fork, data->count_philo );
    data->person = (t_philo_brain *)malloc(sizeof(t_philo_brain) * data->count_philo);
    if (!data->person || !data->fork)
        return (free(data->person), free(data->fork),"1");
    while (i < data->count_philo)
    {
        data->person[i].idx = i + 1;
        data->person[i].time_to_die = data->time_to_die;
        data->person[i].time_to_eat = data->time_to_eat;
        data->person[i].time_to_sleep = data->time_to_sleep;
        if (data->eat_flag)
            data->person[i].least_eat = data->least_eat;
        if (i == 0)
        {
            data->person[i].right_fork = &data->fork[i];
            data->person[i].left_fork = &data->fork[data->count_philo - 1];
        }
        else
        {
            data->person[i].right_fork = &data->fork[i];
            data->person[i].left_fork = &data->fork[i - 1];
        }
        i++;
    }
    return (0);
}