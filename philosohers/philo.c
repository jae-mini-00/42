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
    t_data *num = (t_data *)arg;
    pthread_mutex_lock(&num->mutex);
    num->fork[num->i] += 1;
    printf("스레드가 실행됩니다. 전달된 포크 값: %d\n", num->fork[num->i]);
    pthread_mutex_unlock(&num->mutex);
    return NULL;
}

void philo_init(t_data *philo, char *num_of_people)
{
    philo->i = 0;
    pthread_mutex_init(&philo->mutex, NULL);
    philo->fork = (char *)malloc(sizeof(char) * ft_atoi(num_of_people));
    memset(philo->fork, 0, ft_atoi(num_of_people));
    philo->thread = (pthread_t *)malloc(sizeof(pthread_t) * ft_atoi(num_of_people));
    //if (!philo->thread)
    //    return ;
}

int main(int ac, char **av)
{
    t_data philo;
    int i = 0;

    if (ac != 6 && ac != 5)
        return (0);
    philo_init(&philo, av[1]);
    while (i < ft_atoi(av[1]))
    {
        philo.i = i;
        if (pthread_create(philo.thread + i, NULL, philo_life, &philo) != 0)
        {
            perror("스레드 생성 실패");
            return 1;
        }
        printf("철학자 %d\n", i + 1);
        i++;
    }
    pthread_join(philo.thread[i - 1], NULL);
    printf("메인 스레드 종료\n");
    return 0;
}