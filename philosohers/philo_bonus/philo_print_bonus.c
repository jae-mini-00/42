/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:05:54 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/22 22:05:56 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_sleep(t_philo *data, t_philo_brain *person)
{
	sem_wait(data->print_sem);
	printf("%lld %d is sleeping\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
}

void	print_think(t_philo *data, t_philo_brain *person)
{
	sem_wait(data->print_sem);
	printf("%lld %d is thinking\n", get_time_stamp_ms(), person->idx);
	sem_post(data->print_sem);
}
