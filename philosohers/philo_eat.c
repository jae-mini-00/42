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
		if (check_die(data, data->last_eat_time))
			return (1);
		/*pthread_mutex_lock(&data->finish_mutex[0]);
		if (data->finish_flag[0])
		{
			pthread_mutex_unlock(&data->finish_mutex[0]);
			return (1);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);*/
	}
	pthread_mutex_lock(&data->print_mutex[0]);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), idx);
	pthread_mutex_unlock(&data->print_mutex[0]);
	return (0);
}

int	try_eat(t_philo_brain *data)
{
	data->last_eat_time = get_time_stamp_ms();
	if (data->time_to_die + data->last_eat_time < get_time_stamp_ms())
	{
		pthread_mutex_lock(&data->finish_mutex[0]);
		if (!data->finish_flag[0])
		{
			data->finish_flag[0] = 1;
			pthread_mutex_lock(&data->print_mutex[0]);
			printf("%lld %d died\n", get_time_stamp_ms(), data->idx);
			pthread_mutex_unlock(&data->print_mutex[0]);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);
		return (1);
	}
	data->count_eat++;
	pthread_mutex_lock(&data->finish_mutex[0]);
	if (!data->finish_flag[0])
	{
		pthread_mutex_lock(&data->print_mutex[0]);
		printf("%lld %d is eating\n", data->last_eat_time, data->idx);
		pthread_mutex_unlock(&data->print_mutex[0]);
	}
	pthread_mutex_unlock(&data->finish_mutex[0]);
	return (0);
}

int	philo_eating(t_philo_brain *data)
{
	if (retry_fork(data, data->right_fork_mutex, data->right_fork, data->idx))
		return (1);
	if (retry_fork(data, data->left_fork_mutex, data->left_fork, data->idx))
		return (1);
	if (try_eat(data))
		return (1);
	ft_msleep(data->time_to_eat);
	pthread_mutex_lock(data->left_fork_mutex);
	data->left_fork[0] = 1;
	pthread_mutex_unlock(data->left_fork_mutex);
	pthread_mutex_lock(data->right_fork_mutex);
	data->right_fork[0] = 1;
	pthread_mutex_unlock(data->right_fork_mutex);
	return (0);
}
