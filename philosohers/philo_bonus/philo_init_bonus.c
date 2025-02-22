/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:28:01 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/22 15:28:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	semaphore_init(t_philo *data)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/finish");
	sem_unlink("/count_eat");
	data->fork_sem = sem_open("/fork", O_CREAT, 0644, data->count_philo);
	data->print_sem = sem_open("/print", O_CREAT, 0644, 1);
	data->finish_sem = sem_open("/finish", O_CREAT, 0644, 1);
	data->count_eat_sem = sem_open("/count_eat", O_CREAT, 0644, 1);
}

int	philo_init(t_philo *data, int ac, char **av)
{
	if (ac != 6 && ac != 5)
		return (false);
	data->count_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->least_eat = ft_atoi(av[5]);
	else
		data->least_eat = -1;
	if (!parse_data(data))
		return (false);
	data->person = malloc(sizeof(t_philo_brain) * ft_atoi(av[1]));
	semaphore_init(data);
	return (true);
}

int	philo_brain_init(t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data->count_philo)
	{
		data->person[i].idx = i + 1;
		data->person[i].count_eat = 0;
		data->person[i].last_eat_time = 0;
		data->person[i].finish_flag = 0;
	}
	return (true);
}
