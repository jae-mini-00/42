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

void	retry_fork(t_philo *data, t_philo_brain *person)
{
	sem_wait(data->fork_sem);
	check_die(person, data);
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
	sem_wait(data->fork_sem);
	check_die(person, data);
	sem_wait(data->print_sem);
	printf("%lld %d has taken a fork\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
	person->last_eat_time = get_time_stamp_ms();
}

void	try_eat(t_philo *data, t_philo_brain *person)
{
	check_die(person, data);
	person->count_eat++;
	sem_wait(data->print_sem);
	printf("%lld %d is eating\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
}

void	philo_eat(t_philo *data, t_philo_brain *person)
{
	retry_fork(data, person);
	try_eat(data, person);
	ft_msleep(data->time_to_eat, person, data);
	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
}
