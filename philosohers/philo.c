/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/11 16:40:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    //pthread_mutex_init(&data->mutex, NULL);
    data->fork = (int *)malloc(sizeof(int) * ft_atoi(av[1]));
    data->fork = int_memset(data->fork, data->count_philo );
    data->person = (t_philo_brain *)malloc(sizeof(t_philo_brain) * ft_atoi(av[1]));
    if (!data->person || !data->fork)
        return (free(data->person), free(data->fork),"1");
    return (0);
}

int main(int ac, char **av)
{
    t_philo data;

    if (philo_init(&data, ac, av))
    {
        printf ("arguments should be greater than 0 or few arguments\n");
        return (1);
    }
    if (philo_brain_init(&data))
    /*while (i < philo.how_many_people)
    {
        if (pthread_create(philo.thread + i, NULL, philo_life, &philo) != 0)
        {
            perror("스레드 생성 실패");
            return 0;
        }
        i++;
    }
    while (--i > -1)
        pthread_join(philo.thread[i], NULL);
    free(philo.thread);
    free(philo.fork);*/
    printf("메인 스레드 종료\n");
    return 0;
}