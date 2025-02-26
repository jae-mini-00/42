/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:57:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/22 18:57:24 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_life(t_philo *data, t_philo_brain *person)
{
	while (1)
	{
		check_die(person, data);
		usleep(200);
		philo_eat(data, person);
		if (person->count_eat == data->least_eat + 1)
		{
			all_free(data);
			exit(1);
		}
		print_sleep(data, person);
		ft_msleep(data->time_to_sleep, person, data);
		print_think(data, person);
	}
}

void	philo_start(t_philo *data, int i)
{
	while (i < data->count_philo)
	{
		data->pid[i] = fork();
		if (data->pid[i] == 0)
		{
			philo_life(data, &data->person[i]);
			return ;
		}
		else
			i += 2;
	}
	return ;
}

int	creat_philo(t_philo *data)
{
	int	i;

	i = 0;
	philo_start(data, i);
	if (data->time_to_die > data->time_to_eat)
		usleep(data->time_to_eat * 500);
	else
		usleep(data->time_to_die * 500);
	i = 1;
	philo_start(data, i);
	kill_philo(data);
	return (0);
}
