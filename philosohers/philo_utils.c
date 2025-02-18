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

unsigned int	ft_atoi(const char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] >= 9 && (str[i] <= 13 || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

void	*int_memset(int *fork, int size)
{
	int	i;

	i = 0;
	if (!fork)
		return (NULL);
	while (i < size)
	{
		fork[i] = 1;
		i++;
	}
	return (fork);
}

int	parse_data(t_philo *data)
{
	int	flag;

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

int	check_die(t_philo_brain *data)
{
	const long long	now = get_time_stamp_ms();

	pthread_mutex_lock(&data->finish_mutex[0]);
	if (data->finish_flag[0])
	{
		pthread_mutex_unlock(&data->finish_mutex[0]);
		return (1);
	}
	else
	{
		if (now >= data->time_to_die + data->last_eat_time)
		{
			data->finish_flag[0] = 1;
			pthread_mutex_unlock(&data->finish_mutex[0]);
			pthread_mutex_lock(&data->print_mutex[0]);
			printf("%lld %d died\n", get_time_stamp_ms(), data->idx);
			pthread_mutex_unlock(&data->print_mutex[0]);
			return (1);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);
	}
	return (0);
}

void	ft_msleep(long long ms, t_philo_brain *data)
{
	const long long		begin = get_time_stamp_ms();
	long long			left_time;

	while (1)
	{
		left_time = get_time_stamp_ms() - begin;
		if (left_time >= ms)
			break ;
		if (ms - left_time <= 10)
			usleep(((ms - left_time) * 1000) / 4);
		else
			usleep(8000);
		if (check_die(data))
			return ;
	}
}
