/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:16:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:48:46 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_full_path_split(char **path_split)
{
	int	i;
	char	*temp;

	i = 0;
	while (path_split[i])
	{
		temp = path_split[i];
		path_split[i] = ft_strjoin(path_split[i], "/");
		free(temp);
		i++;
	}
	return (path_split);
}

static char	**path_init(char **envp)
{
	int	i;
	char *path;
	char **path_split;

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
	path_split = ft_full_path_split(path_split);
	return (path_split);
}
static void	access_path(t_data *minishell)
{
	int		i;
	char	*temp;

	i = 0;
	while (minishell->path[i])
	{
		temp = ft_strjoin(minishell->path[i], minishell->o_cmd_split[0]);
		if (access(temp, X_OK) == 0)
		{
			free(minishell->o_cmd_split[0]);
			minishell->o_cmd_split[0] = ft_strdup(temp);
			free(temp);
			return ;
		}
		free(temp);
		i++;
	}
}
void	o_cmd_split_init(t_data *minishell)
{
	int i;

	i = 0;
	while (minishell->o_cmd[i] == ' ')
		i++;
	if (minishell->o_cmd[i] == '\n' || minishell->o_cmd[i] == '\0')
	{
		minishell->o_cmd_split = NULL;
		return ;
	}
	minishell->o_cmd_split = ft_split(&minishell->o_cmd[i], ' ');
	if (minishell->o_cmd[i] == '~' || minishell->o_cmd[i] == '.' || minishell->o_cmd[i] == '/')
		return ;
	else
		access_path(minishell);
	builtin_check(minishell);
}
void	minishell_init(t_data *minishell, char **envp)
{
	int	i;

	i = 0;
	while(envp[i])
		i++;
	minishell->builtin_flag = 0;
	minishell->pipe_flag = 0;
	minishell->o_cmd = NULL;
	minishell->o_cmd_split = NULL;
	minishell->path = path_init(envp);
	minishell->env = (char **)malloc(sizeof(char *) * (i + 1));
	minishell->env[i--] = NULL;
	while (i > -1)
	{
		minishell->env[i] = ft_strdup(envp[i]);
		i--;
	}
}