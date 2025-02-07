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

void *philo_life(void *arg)
{
    int turn;
    //int eat_flag;

    //eat_flag = 0;
    t_data *num = (t_data *)arg;
    while (1)
    {
        pthread_mutex_lock(&num->mutex);
        turn = num->i++;
        if (turn != 0)
        {
            if (num->fork[turn] && num->fork[turn - 1])
            {
                //eat_flag = 1;
                num->fork[turn] -= 1;
                num->fork[turn - 1] -= 1;
            }
            else
                printf("%d i don't have fork\n", turn + 1);
            printf("%d has taken a fork\nright :%d left :%d\n\n", turn + 1, num->fork[turn], num->fork[turn - 1]);
        }
        else
        {
            if (num->fork[turn] && num->fork[num->how_many_people - 1])
            {
                //eat_flag = 1;
                num->fork[turn] -= 1;
                num->fork[num->how_many_people - 1] -= 1;
            }
            else
                printf("%d i don't have fork\n", turn + 1);
            printf("%d has taken a fork\nright :%d left :%d\n\n", turn + 1, num->fork[turn], num->fork[num->how_many_people - 1]);
        }
        pthread_mutex_unlock(&num->mutex);
        /*if (eat_flag)
        {
            ft_eat();
            ft_sleeping();
        }
        else
        {
            ft_thinking();
        }*/
        return NULL;
    }
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

void *philo_init(t_data *philo, char **data)
{
    philo->i = 0;
    philo->die_flag = 0;
    philo->how_many_people = ft_atoi(data[1]);
    philo->time_to_eat = ft_atoi(data[2]);
    philo->time_to_sleep = ft_atoi(data[3]);
    if (data[4])
        philo->eat_flag = ft_atoi(data[4]);
    else
        philo->eat_flag = 0;
    pthread_mutex_init(&philo->mutex, NULL);
    philo->fork = (int *)malloc(sizeof(int) * ft_atoi(data[1]));
    philo->fork = int_memset(philo->fork, philo->how_many_people );
    philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(data[1]));
    if (!philo->thread || !philo->fork)
        return (free(philo.thread), free(philo.fork),"1");
    return (0);
}




int main(int ac, char **av)
{
    t_data philo;
    int i = 0;

    if ((ac != 6 && ac != 5) || ft_atoi(av[1]) < 2)
        return (0);
    if (philo_init(&philo, av))
        return (0);
    while (i < philo.how_many_people)
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
    free(philo.fork);
    printf("메인 스레드 종료\n");
    return 0;
}