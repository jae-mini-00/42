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
		sem_wait(data->finish_sem);
		if (person->finish_flag)
		{
			sem_post(data->finish_sem);
			return ;
		}
		sem_post(data->finish_sem);
		philo_eat(data, person);
		print_sleep(data, person);
		ft_msleep(data->time_to_sleep, person);
		print_think(data, person);
	}
}

void	philo_start(t_philo *data, int i)
{
	while (i < data->count_philo)
	{
		data->pid = fork();
		if (data->pid == 0)
			i += 2;
		else
		{
			philo_life(data, &data->person[i]);
			break ;
		}
	}
	waitpid(data->pid, NULL, 0);
}

void	creat_philo(t_philo *data)
{
	int	i;

	i = 0;
	philo_start(data, i);
	if (data->time_to_die > data->time_to_eat)
		usleep(data->time_to_eat * 500);
	else
		usleep(data->time_to_die * 500);
	i = 1;
	if (data->pid == 0)
		philo_start(data, i);
}
