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

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo_brain
{
	pthread_t		thread;
	pthread_mutex_t	*right_fork_mutex;
	pthread_mutex_t	*left_fork_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*finish_mutex;
	int				*left_fork;
	int				*right_fork;
	int				*finish_flag;
	int				idx;
	int				count_eat;
	int				least_eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		last_eat_time;
}	t_philo_brain;

typedef struct s_philo
{
	t_philo_brain		*person;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		*finish_mutex;
	int					*fork;
	int					eat_flag;
	int					least_eat;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					count_philo;
	int					die_flag;
	int					finish_flag;
}	t_philo;
/* init */
void			*philo_brain_init(t_philo *data);
void			*philo_init(t_philo *data, int ac, char **av);
/* utils */
unsigned int	ft_atoi(const char *str);
void			*int_memset(int *fork, int size);
int				parse_data(t_philo *data);
void			ft_msleep(long long ms, t_philo_brain *data);
int				check_die(t_philo_brain *data);
/* time_tamp */
void			time_stamp_init(void);
long long		get_time_stamp_ms(void);
/* eat */
int				try_fork(pthread_mutex_t *mutex, int *fork);
int				retry_fork(t_philo_brain *data, \
		pthread_mutex_t *mutex, int *fork, int idx);
int				try_eat(t_philo_brain *data);
int				philo_eating(t_philo_brain *data);
/* print */
void			print_think(t_philo_brain *data);
void			print_sleep(t_philo_brain *data);
/* start */
void			*start_philo(t_philo *data);
void			end_free(t_philo *data);

#endif
