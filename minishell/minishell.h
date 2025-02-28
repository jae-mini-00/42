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

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_path
{
	pid_t	pid;
	int		cmd_flag;
	char	*o_cmd;
	char	**path;
	char	**o_cmd_split;
	char	**cmd;
} t_path;

/* init */
char	**path_init(char **envp);

/* free */
void	split_free(char **split);

/* cmd check */
void	cmd_check(t_path *data, char *cmd);

/* fork */
void	make_fork(t_path *data, char **envp);

#endif
