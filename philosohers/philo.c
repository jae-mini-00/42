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
	t_philo_brain	*data;

	data = (t_philo_brain *)philo;
	data->count_eat = 0;
	while (1)
	{
		pthread_mutex_lock(&data->finish_mutex[0]);
		if (data->finish_flag[0])
		{
			pthread_mutex_unlock(&data->finish_mutex[0]);
			return (NULL);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);
		if (philo_eating(data))
			return ("1");
		print_sleep(data);
		ft_msleep(data->time_to_sleep);
		print_think(data);
	}
	return (0);
}

void	*start_philo(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
		if (pthread_create(&data->person[i].thread, NULL, \
					 	philo_life, &data->person[i]) != 0)
		{
			printf("pthread_create error\n");
			return (free(data), "1");
		}
		i += 2;
	}
	i = 1;
	if (data->time_to_die > data->time_to_eat)
		usleep(data->time_to_eat * 500);
	else
		usleep(data->time_to_die * 500);
	while (i < data->count_philo)
	{
		if (pthread_create(&data->person[i].thread, NULL, \
					 	philo_life, &data->person[i]) != 0)
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
		printf ("arguments should be greater than 0 or incorrect arguments\n");
		return (1);
	}
	philo_brain_init(&data);
	time_stamp_init();
	start_philo(&data);
	pthread_join(data.person[0].thread, NULL);
	return (0);
}
