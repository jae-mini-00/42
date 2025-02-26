/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_end_free_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:31:03 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/23 17:31:05 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	all_free(t_philo *data)
{
	free(data->pid);
	free(data->person);
	sem_close(data->fork_sem);
	sem_close(data->print_sem);
}

void	all_free_sem(void)
{
	sem_unlink("/fork");
	sem_unlink("/print");
}

void	kill_philo(t_philo *data)
{
	int	status;
	int	count;

	count = 0;
	while (count < data->count_philo)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			count = 0;
			while (count < data->count_philo)
				kill (data->pid[count++], SIGKILL);
			return ;
		}
		count++;
	}
	return ;
}
