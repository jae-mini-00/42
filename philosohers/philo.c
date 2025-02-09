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

int main(int ac, char **av)
{
    t_philo data;

    if (philo_init(&data, ac, av))
    {
        printf ("arguments should be greater than 0 or few arguments\n");
        return (1);
    }
    if (philo_brain_init(&data))
        return (1);
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
    time_stamp_init();
    printf("메인 스레드 종료\n");
    return 0;
}