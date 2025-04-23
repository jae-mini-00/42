/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:16:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/23 22:45:49 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	path = NULL;
	path_split = NULL;
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
	if (!envp[i])
		return (NULL);
	free(path);
	ft_full_path_split(path_split);
	return (path_split);
}

static char	*tab_trance_space(char *str)
{
	int		i;
	char	quite;
	char	*temp;

	i = 0;
	quite = 0;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	while (str[i])
	{
		if (!quite && (str[i] == '\'' || str[i] == '"'))
			quite = str[i];
		else if (quite && (str[i] == quite))
			quite = 0;
		if (str[i] == '\t' && !quite)
			temp[i] = ' ';
		else
			temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	o_cmd_split_init(t_data *minishell)
{
	int		i;
	char	*temp;

	i = 0;
	minishell->pid = 0;
	minishell->here_doc_count = 0;
	temp = tab_trance_space(minishell->o_cmd);
	while (temp[i] == ' ')
		i++;
	if (temp[i] == '\n' || temp[i] == '\0')
		return (free(temp));
	split_free(minishell->path);
	minishell->path = path_init(minishell->env);
	minishell->token = token_init(temp);
	minishell_variable_expansion(minishell->token, minishell);
	type_trance(minishell->token, minishell, 0);
	free(temp);
}

void	minishell_init(t_data *minishell, char **envp, char *av)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	if (av)
		minishell->mode = ft_atoi(av);
	else
		minishell->mode = 0;
	minishell->exit_code = 0;
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
