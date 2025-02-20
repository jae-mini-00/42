/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:02:12 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/18 19:02:14 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_think(t_philo_brain *data)
{
	pthread_mutex_lock(data->finish_mutex);
	if (*data->finish_flag)
		pthread_mutex_unlock(data->finish_mutex);
	else
	{
		pthread_mutex_lock(data->print_mutex);
		printf("%lld %d is thinking\n", get_time_stamp_ms(), data->idx);
		pthread_mutex_unlock(data->print_mutex);
		pthread_mutex_unlock(data->finish_mutex);
	}
}

void	print_sleep(t_philo_brain *data)
{
	pthread_mutex_lock(data->finish_mutex);
	if (*data->finish_flag)
		pthread_mutex_unlock(data->finish_mutex);
	else
	{
		pthread_mutex_lock(data->print_mutex);
		printf("%lld %d is sleeping\n", get_time_stamp_ms(), data->idx);
		pthread_mutex_unlock(data->print_mutex);
		pthread_mutex_unlock(data->finish_mutex);
	}
}
