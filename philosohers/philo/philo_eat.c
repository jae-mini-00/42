/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:02:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/18 19:02:22 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	try_fork(pthread_mutex_t *mutex, int *fork)
{
	pthread_mutex_lock(mutex);
	if (fork[0])
	{
		fork[0] = 0;
		pthread_mutex_unlock(mutex);
		return (0);
	}
	pthread_mutex_unlock(mutex);
	return (1);
}

int	retry_fork(t_philo_brain *data, pthread_mutex_t *mutex, int *fork, int idx)
{
	while (try_fork(mutex, fork))
	{
		if (check_die(data))
			return (1);
		usleep(200);
	}
	pthread_mutex_lock(data->print_mutex);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), idx);
	pthread_mutex_unlock(data->print_mutex);
	return (0);
}

int	try_eat(t_philo_brain *data)
{
	check_die(data);
	data->last_eat_time = get_time_stamp_ms();
	data->count_eat++;
	pthread_mutex_lock(data->finish_mutex);
	if (!*data->finish_flag)
	{
		pthread_mutex_lock(data->print_mutex);
		printf("%lld %d is eating\n", data->last_eat_time, data->idx);
		pthread_mutex_unlock(data->print_mutex);
	}
	pthread_mutex_unlock(data->finish_mutex);
	return (0);
}

void	check_least_eat(t_philo_brain *data)
{
	pthread_mutex_lock(data->count_eat_mutex);
	if (data->count_eat == data->least_eat + 1)
		*data->count_eat_flag += 1;
	if (*data->count_eat_flag == data->count_philo)
	{
		pthread_mutex_lock(data->finish_mutex);
		*data->finish_flag = 1;
		pthread_mutex_unlock(data->finish_mutex);
	}
	pthread_mutex_unlock(data->count_eat_mutex);
}

int	philo_eating(t_philo_brain *data)
{
	if (retry_fork(data, data->right_fork_mutex, data->right_fork, data->idx))
		return (1);
	if (retry_fork(data, data->left_fork_mutex, data->left_fork, data->idx))
		return (1);
	if (try_eat(data))
		return (1);
	ft_msleep(data->time_to_eat, data);
	pthread_mutex_lock(data->left_fork_mutex);
	*data->left_fork = 1;
	pthread_mutex_unlock(data->left_fork_mutex);
	pthread_mutex_lock(data->right_fork_mutex);
	*data->right_fork = 1;
	pthread_mutex_unlock(data->right_fork_mutex);
	if (data->least_eat)
		check_least_eat(data);
	return (0);
}
