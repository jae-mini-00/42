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

int	main(int ac, char **av)
{
	t_philo	data;

	if (!philo_init(&data, ac, av))
	{
		printf ("arguments should be greater than 0 or incorrect arguments\n");
		return (0);
	}
	if (!philo_brain_init(&data))
	{
		printf ("brain init fail\n");
		return (0);
	}
	time_stamp_init();
	creat_philo(&data);
	all_free(&data);
	all_free_sem();
	return (0);
}
