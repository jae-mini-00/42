/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/11 16:40:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_philo_brain
{
	int				idx;
	int				count_eat;
	int				finish_flag;
	long long		last_eat_time;
}	t_philo_brain;

typedef struct s_philo
{
	t_philo_brain		*person;
	pid_t				pid;
	sem_t				*fork_sem;
	sem_t				*print_sem;
	sem_t				*finish_sem;
	sem_t				*count_eat_sem;
	int					least_eat;
	int					count_philo;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
}	t_philo;

/* init */
int				philo_init(t_philo *data, int ac, char **av);
int				philo_brain_init(t_philo *data);
/* time_stamp */
long long		get_time_stamp_ms(void);
void			time_stamp_init(void);
/* creat_philo */
void			creat_philo(t_philo *data);
/* utils */
unsigned int	ft_atoi(const char *str);
int				parse_data(t_philo *data);
void			ft_msleep(long long ms, t_philo_brain *data);
/* eat */
void			philo_eat(t_philo *data, t_philo_brain *person);
/* print */
void			print_sleep(t_philo *data, t_philo_brain *person);
void			print_think(t_philo *data, t_philo_brain *person);

#endif
