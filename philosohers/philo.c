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

void	*philo_life(void *philo)
{
	t_philo_brain *data = (t_philo_brain *)philo;
	
	pthread_mutex_lock(data->print_mutex);
	printf("철학자 :%d\n", data->idx);
	printf("안녕하세요!\n");
	printf("bye!\n\n");
	pthread_mutex_unlock(data->print_mutex);
	return (0);
}

void	*start_philo(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
        if (pthread_create(&data->person[i].thread, NULL, philo_life, &data->person[i]) != 0)
        {
            printf("pthread_create error\n");
			return (free(data), "1");
        }
        i += 2;
    }
	i = 1;
	while (i < data->count_philo)
	{
        if (pthread_create(&data->person[i].thread, NULL, philo_life, &data->person[i]) != 0)
        {
            printf("pthread_create error\n");
			return (free(data), "1");
        }
        i += 2;
    }
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	data;

	if (philo_init(&data, ac, av))
	{
		printf ("arguments should be greater than 0 or few arguments\n");
		return (1);
	}
	philo_brain_init(&data);
	//	return (1);
	time_stamp_init();
	start_philo(&data);
	/*while (i < philo.how_many_people)
	{
        if (pthread_create(philo.thread + i, NULL, philo_life, &philo) != 0)
        {
            perror("스레드 생성 실패");
            return 0;
        }
        i++;
    }*/
	int i = data.count_philo;
    while (--i > -1)
	{
        pthread_join(data.person[i].thread, NULL);
	}
	printf ("메인 스레드 종료\n");
	return 0;
}
	/*int i;
	
	i = 0;
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else if (i == data.count_philo - 1)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[0]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i + 1]);
		i++;
	}
	i = 0;
	printf ("\n\n");
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else if (i == data.count_philo - 1)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[0]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i + 1]);
		i++;
	}*/
