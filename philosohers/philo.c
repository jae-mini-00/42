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

int	try_fork(pthread_mutex_t *mutex, int *fork)
{
	pthread_mutex_lock(mutex);
	if (fork)
	{
		fork[0] = 0;
		pthread_mutex_unlock(mutex);
		return (0);
	}
	pthread_mutex_unlock(mutex);
	return (1);
}

int	*retry_fork(t_philo_brain *data, pthread_mutex_t *mutex, int *fork, int idx)
{
	while (try_fork(mutex, fork))
	{
		pthread_mutex_lock(&data->finish_mutex[0]);
		if (data->finish_flag)
		{
			pthread_mutex_lock(&data->finish_mutex[0]);
			return (1);
		}
		pthread_mutex_lock(&data->finish_mutex[0]);
	}
	printf("%lld %d has taken a fork", get_time_stamp_ms(), idx);
	return (0);
}

int	try_eat(t_philo_brain *data)
{
	data->last_eat_time = get_time_stamp_ms();
	if (data->time_to_die + data->last_eat_time < get_time_stamp_ms())
	{
		pthread_mutex_lock(&data->finish_mutex[0]);
		if (!data->finish_flag)
		{
			data->finish_flag = 1;
			pthread_mutex_lock(&data->print_mutex[0]);
			printf("%lld %d died\n", get_timestamp_ms(), data->idx);
			pthread_mutex_unlock(&data->print_mutex[0]);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);
		return (1);
	}
	data->count_eat++;
	pthread_mutex_lock(&data->finish_mutex[0]);
	if (!data->finish_flag)
	{
		pthread_mutex_lock(&data->print_mutex[0]);
		printf("%lld %d is eating\n", data->last_eat_time, data->idx);
		pthread_mutex_unlock(&data->print_mutex[0]);
	}
	pthread_mutex_unlock(&data->finish_mutex[0]);
	return (0);
}

void	philo_eating(t_philo_brain *data)
{
	retry_fork(data, data->right_fork_mutex, data->fork, data->idx);
	retry_fork(data, data->left_fork_mutex, data->fork, data->idx);
	try_eat(data);
	pthread_mutex_lock(data->left_fork_mutex);
	me->left_fork[0] = 0;
	pthread_mutex_unlock(data->left_fork_mutex);
	pthread_mutex_lock(data->right_fork_mutex);
	me->right_fork[0] = 0;
	pthread_mutex_unlock(data->right_fork_mutex);
}


void	*philo_life(void *philo)
{
	t_philo_brain *data = (t_philo_brain *)philo;

	data->count_eat = 0;
	while(1)
	{
		pthread_mutex_lock(&data->finish_mutex[0]);
		if (data->finish_flag)
		{
			pthread_mutex_unlock(&data->finish_mutex[0]);
			return (NULL);
		}
		pthread_mutex_unlock(&data->finish_mutex[0]);
		philo_eating(data);
	}
	return (0);
}

void	*start_philo(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->count_philo)
	{
        if (pthread_create(&data->person[i].thread, NULL, philo_life, &data->person[i]) != 0)
        {
            printf("pthread_create error\n");
			return (free(data), "1");
        }
        i += 2;
    }
	i = 1;
	while (i < data->count_philo)
	{
        if (pthread_create(&data->person[i].thread, NULL, philo_life, &data->person[i]) != 0)
        {
            printf("pthread_create error\n");
			return (free(data), "1");
        }
        i += 2;
    }
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	data;

	if (philo_init(&data, ac, av))
	{
		printf ("arguments should be greater than 0 or incorrect arguments\n");
		return (1);
	}
	philo_brain_init(&data);
	//	return (1);
	time_stamp_init();
	//start_philo(&data);
	return 0;
}
	/*int i;
	
	i = 0;
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i - 1]);
		i++;
	}
	i = 0;
	data.person[4].right_fork[0] = 0;
	data.person[4].left_fork[0] = 0;
	printf ("\n\n");
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i - 1]);
		i++;
	}*/
