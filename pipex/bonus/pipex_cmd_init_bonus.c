/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/11 16:40:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*cmd_path(char *av, char **path)
{
	int		i;
	char	*temp;
	char	*full_cmd;

	i = 0;
	temp = ft_strdup(av);
	while (path[i])
	{
		full_cmd = ft_strjoin(path[i], av);
		if (access(full_cmd, X_OK) == 0)
		{
			free(av);
			av = ft_strdup(full_cmd);
			free(full_cmd);
			free(temp);
			return (av);
		}
		free(full_cmd);
		i++;
	}
	free(av);
	return (temp);
}

t_cmdlist	*make_cmd_data(char *av, char **path)
{
	t_cmdlist	*now;

	now = (t_cmdlist *)malloc(sizeof(t_cmdlist) * 1);
	if (!now)
		return (NULL);
	now->av = ft_split(av, ' ');
	if (*now->av)
		now->av[0] = cmd_path(now->av[0], path);
	now->next = NULL;
	return (now);
}

void	connect_cmd(t_cmdlist *cmd, t_cmdlist *new)
{
	t_cmdlist	*now;

	now = cmd;
	while (now->next)
		now = now->next;
	now->next = new;
}

t_cmdlist	*cmd_init(t_bonusdata *data, int ac, char **av, char **path)
{
	int			i;
	int			num;
	t_cmdlist	*new;

	i = 2;
	num = 1;
	data->cmd = make_cmd_data(av[i++], path);
	data->cmd->num = num++;
	data->cmd_size = 1;
	while (i < ac - 1)
	{
		new = make_cmd_data(av[i], path);
		new->num = num++;
		connect_cmd(data->cmd, new);
		data->cmd_size += 1;
		i++;
	}
	return (data->cmd);
}
