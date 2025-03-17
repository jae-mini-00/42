/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/17 18:41:38 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FREE_H
# define MINISHELL_FREE_H

# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/wait.h>

typedef enum s_type
{
	COMMAND,
	BUILTIN,
	ARG,
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
	char	*prompt;
	char	*o_cmd;
	char	**env;
	char	**path;
	t_token	*token;
}	t_data;

/* free */
void	split_free(char **split);
void	minishell_free(t_data *minishell);
void	token_free(t_token *data);
void	exit_free(t_data *minishell);

#endif
