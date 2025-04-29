/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/30 04:15:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FREE_H
# define MINISHELL_FREE_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef enum s_type
{
	COMMAND,
	BUILTIN,
	ARG,
	REDIRECTION,
	HERE_DOC,
	PIPE,
	ENV,
	REMOVE,
	IO_FILE
}	t_type;

typedef struct s_token
{
	char			*value;
	int				fd;
	int				quite_flag;
	t_type			type;
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	pid_t	*pid;
	int		here_doc_count;
	int		mode;
	int		exit_code;
	char	*prompt;
	char	*o_cmd;
	char	**env;
	char	**path;
	t_token	*token;
}	t_data;

/* free */
void	split_free(char **split);
void	token_free(t_token *data);
void	minishell_free(t_data *minishell);
void	exit_free(t_data *minishell, int num);
void	here_doc_free(int fd, int infd, char *temp);

#endif
