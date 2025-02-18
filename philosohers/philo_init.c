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

void	philo_fork_init(t_philo *data, int i)
{
	if (i == 0)
	{
		data->person[i].right_fork = &data->fork[i];
		data->person[i].left_fork = &data->fork[data->count_philo - 1];
	}
	else
	{
		data->person[i].right_fork = &data->fork[i];
		data->person[i].left_fork = &data->fork[i - 1];
	}
	if (i == 0)
	{
		data->person[i].right_fork_mutex = &data->fork_mutex[i];
		data->person[i].left_fork_mutex = \
			&data->fork_mutex[data->count_philo - 1];
	}
	else
	{
		data->person[i].right_fork_mutex = &data->fork_mutex[i];
		data->person[i].left_fork_mutex = &data->fork_mutex[i - 1];
	}
}

void	*philo_init(t_philo *data, int ac, char **av)
{
	int	i;

	i = 0;
	data->eat_flag = 0;
	data->die_flag = 0;
	data->finish_flag = 0;
	data->count_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->least_eat = ft_atoi(av[5]);
		data->eat_flag = 1;
	}
	if (parse_data(data) && (ac != 5 && ac != 6))
		return ("1");
	data->finish_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->finish_mutex[0], NULL);
	data->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
											data->count_philo);
	while (i < data->count_philo)
		pthread_mutex_init(&data->fork_mutex[i++], NULL);
	return (0);
}

void	*philo_brain_init(t_philo *data)
{
	int	i;

	i = 0;
	data->print_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->print_mutex[i], NULL);
	data->fork = (int *)malloc(sizeof(int) * data->count_philo);
	data->fork = int_memset(data->fork, data->count_philo);
	data->person = malloc(sizeof(t_philo_brain) * data->count_philo);
	if (!data->person || !data->fork)
		return (free(data->person), free(data->fork), "1");
	while (i < data->count_philo)
	{
		data->person[i].idx = i + 1;
		data->person[i].finish_flag = &data->finish_flag;
		data->person[i].print_mutex = &data->print_mutex[0];
		data->person[i].finish_mutex = &data->finish_mutex[0];
		data->person[i].time_to_die = data->time_to_die;
		data->person[i].time_to_eat = data->time_to_eat;
		data->person[i].time_to_sleep = data->time_to_sleep;
		if (data->eat_flag)
			data->person[i].least_eat = data->least_eat;
		philo_fork_init(data, i);
		i++;
	}
	return (0);
}
