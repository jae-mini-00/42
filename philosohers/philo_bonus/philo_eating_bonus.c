/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:08:33 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/22 19:08:35 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	try_fork(t_philo *data, t_philo_brain *person)
{
	sem_wait(data->fork_sem);
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
	sem_wait(data->fork_sem);
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
	person->last_eat_time = get_time_stamp_ms();
	return (0);
}

int	try_eat(t_philo *data, t_philo_brain *person)
{
	sem_wait(data->finish_sem);
	if (person->finish_flag)
	{
		sem_post(data->finish_sem);
		return (1);
	}
	sem_post(data->finish_sem);
	sem_wait(data->print_sem);
	printf("%lld %d is eating\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
	return (0);
}

void	philo_eat(t_philo *data, t_philo_brain *person)
{
	if (try_fork(data, person))
		return ;
	if (try_eat(data, person))
		return ;
	ft_msleep(data->time_to_eat, person);
	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
	return ;
}
