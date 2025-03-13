/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:48:03 by jaejo            ###   ########.fr       */
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

typedef enum s_type
{
	COMMAND,
	ARGUMENT,
	REDIRECTION,
	HERE_DOC,
	PIPE,
	ENV
}	t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token *next;
}	t_token;

typedef struct s_data
{
	pid_t	pid;
	int		pipe_flag;
	int		builtin_flag;
	char	*prompt;
	char	*o_cmd;
	char	**o_cmd_split;
	char	**env;
	char	**path;
	t_token	*cmd;
}	t_data;

/* init */
void	minishell_init(t_data *minishell, char **envp);
void	o_cmd_split_init(t_data *minishell);

/* free */
void	split_free(char **split);
void	minishell_free(t_data *minishell);

/* fork */
void	make_fork(t_data *minishell, char **envp);

/* check */
void	builtin_check(t_data *minishell);
int		echo_flag_check(char *str);

/* builtin */
void	ft_env(t_data *minishell);
void	ft_echo(t_data *minishell);
void	ft_cd(char **data);
void	ft_pwd(char **data);
void	ft_export(t_data *minishell);

/* export utils */
void	make_env(t_data *minishell);

/* builtin utils */
int		split_last(char **split);
void	echo_print(t_data *minishell, int i, int flag);

#endif
