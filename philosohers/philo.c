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
	t_philo	data;

	if (philo_init(&data, ac, av))
	{
		printf ("arguments should be greater than 0 or few arguments\n");
		return (1);
	}
	if (philo_brain_init(&data))
		return (1);
	time_stamp_init();
	/*while (i < philo.how_many_people)
	{
        if (pthread_create(philo.thread + i, NULL, philo_life, &philo) != 0)
        {
            perror("스레드 생성 실패");
            return 0;
        }
        i++;
    }
    while (--i > -1)
        pthread_join(philo.thread[i], NULL);
    free(philo.thread);
    free(philo.fork);*/
	int i;
	
	i = 0;
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else if (i == data.count_philo - 1)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[0]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i + 1]);
		i++;
	}
	i = 0;
	data.person[2].right_fork[0] = 0;
	printf ("\n\n");
	while (i < data.count_philo)
	{
		if (i == 0)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[data.count_philo - 1]);
		else if (i == data.count_philo - 1)
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[0]);
		else
			printf("철학자 :%d, 오른손 :%d 왼손 :%d\n", i + 1, data.fork[i], data.fork[i + 1]);
		i++;
	}
	printf ("메인 스레드 종료\n");
	return 0;
}
