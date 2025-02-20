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

int	main(int ac, char **av)
{
	int		i;
	t_philo	data;

	i = 0;
	if (ac != 5 && ac != 6)
		return (1);
	if (philo_init(&data, ac, av))
	{
		printf ("arguments should be greater than 0 or incorrect arguments\n");
		return (1);
	}
	if (philo_brain_init(&data))
		return (1);
	time_stamp_init();
	start_philo(&data);
	while (i < data.count_philo)
		pthread_join(data.person[i++].thread, NULL);
	end_free(&data);
	return (0);
}
