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

#include "philo_bonus.h"

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
	if (str[i])
		return (0);
	return (n);
}

int	parse_data(t_philo *data)
{
	int	flag;

	flag = 1;
	if (!data->count_philo)
		flag = 0;
	else if (!data->time_to_die)
		flag = 0;
	else if (!data->time_to_eat)
		flag = 0;
	else if (!data->time_to_sleep)
		flag = 0;
	else if (!data->least_eat)
		flag = 0;
	return (flag);
}

int	check_die(t_philo_brain *person, t_philo *data)
{
	const long long	now = get_time_stamp_ms();

	if (now >= data->time_to_die + person->last_eat_time)
	{
		sem_wait(data->print_sem);
		printf("%lld %d died\n", get_time_stamp_ms(), person->idx);
		sem_post(data->print_sem);
		all_free(data);
		exit (0);
	}
	return (0);
}

void	ft_msleep(long long ms, t_philo_brain *person, t_philo *data)
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
		if (check_die(person, data))
			return ;
	}
}
