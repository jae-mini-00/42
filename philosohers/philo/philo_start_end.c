/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:08:45 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/18 22:08:47 by jaejo            ###   ########.fr       */
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
		pthread_mutex_lock(data->finish_mutex);
		if (*data->finish_flag)
		{
			pthread_mutex_unlock(data->finish_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(data->finish_mutex);
		if (philo_eating(data))
			return ("1");
		print_sleep(data);
		ft_msleep(data->time_to_sleep, data);
		if (data->least_eat)
			check_least_eat(data);
		print_think(data);
	}
	return (0);
}

void	*make_thread(t_philo *data, int i)
{
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

void	*start_philo(t_philo *data)
{
	int	i;

	i = 0;
	if (make_thread(data, i))
		return ("1");
	i = 1;
	if (data->time_to_die > data->time_to_eat)
		usleep(data->time_to_eat * 300);
	else
		usleep(data->time_to_die * 300);
	if (make_thread(data, i))
		return ("1");
	return (0);
}

void	end_free(t_philo *data)
{
	free(data->person);
	free(data->fork_mutex);
	free(data->print_mutex);
	free(data->finish_mutex);
	free(data->fork);
	if (data->count_eat_mutex)
		free(data->count_eat_mutex);
}
