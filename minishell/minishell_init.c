/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:16:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/14 00:12:33 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int signal_condition;

static void	ft_full_path_split(char **path_split)
{
	int		i;
	char	*temp;

	i = 0;
	while (path_split[i])
	{
		temp = path_split[i];
		path_split[i] = ft_strjoin(path_split[i], "/");
		free(temp);
		i++;
	}
}

static char	**path_init(char **envp)
{
	int		i;
	char	*path;
	char	**path_split;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			path_split = ft_split(path, ':');
			break ;
		}
		i++;
	}
	free(path);
	ft_full_path_split(path_split);
	return (path_split);
}

void	o_cmd_split_init(t_data *minishell)
{
	int	i;

	i = 0;
	minishell->pid = 0;
	signal_condition = 0;
	minishell->here_doc_count = 0;
	while (minishell->o_cmd[i] == ' ')
		i++;
	if (minishell->o_cmd[i] == '\n' || minishell->o_cmd[i] == '\0')
		return ;
	split_free(minishell->path);
	minishell->path = path_init(minishell->env);
	minishell->token = token_init(minishell->o_cmd);
	minishell_variable_expansion(minishell->token, minishell);
	type_trance(minishell->token, minishell, 0);
}

void	minishell_init(t_data *minishell, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	minishell->prompt = NULL;
	minishell->o_cmd = NULL;
	minishell->token = NULL;
	minishell->path = path_init(envp);
	minishell->env = (char **)malloc(sizeof(char *) * (i + 1));
	minishell->env[i--] = NULL;
	while (i > -1)
	{
		minishell->env[i] = ft_strdup(envp[i]);
		i--;
	}
}
