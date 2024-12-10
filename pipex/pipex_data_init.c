/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_data_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:42:58 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/10 18:43:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	**ft_full_path(char **data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data[i])
	{
		temp = data[i];
		data[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	return (data);
}

char	**ft_path_split(char **envp)
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
		}
		i++;
	}
	free(path);
	path_split = ft_full_path(path_split);
	return (path_split);
}

char	*cmd_path(char *av, char **path)
{
	int		i;
	char	*temp;
	char	*full_cmd;

	i = 0;
	temp = av;
	while (path[i])
	{
		full_cmd = ft_strjoin(path[i], av); 
		if (access(full_cmd, X_OK) == 0)
		{
			free(av);
			av = ft_strdup(full_cmd);
			break ;
		}
		free(full_cmd);
		i++;
	}
	if (path[i])
		free(temp);
	return (av);
}

t_cmdlist	*make_cmd_data(char *av, char **path)
{
	t_cmdlist *now;

	now = (t_cmdlist *)malloc(sizeof(t_cmdlist) * 1);
	if (!now)
		return(NULL);
	now->av = ft_split(av, ' ');
	now->av[0] = cmd_path(now->av[0], path);
	now->next = NULL;
	return(now);
}

void	connect_cmd(t_cmdlist *cmd, t_cmdlist *new)
{
	t_cmdlist	*now;

	now = cmd;
	while (now->next)
		now = now->next;
	now->next = new;
}

t_cmdlist	*cmd_init(t_cmdlist *cmd, int ac, char **av, char **path)
{
	int	i;
	int	num;
	t_cmdlist	*new;

	i = 2;
	num = 1;
	cmd = make_cmd_data(av[i++], path);
	cmd->num = num++;
	while (i < ac - 1)
	{
		new = make_cmd_data(av[i], path);
		new->num = num++;
		connect_cmd(cmd, new);
		i++;
	}
	return (cmd);
}

void	pipexdata_init(t_pipexdata *data, int ac, char **av, char **envp)
{
	data->in_file = open(av[1], O_RDONLY);
	data->out_file = open(av[ac - 1], O_TRUNC);
	data->path_split = ft_path_split(envp);
	data->cmd = cmd_init(data->cmd, ac, av, data->path_split);
}
