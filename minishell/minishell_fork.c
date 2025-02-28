/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:26:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/28 17:26:25 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	access_path(t_path *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->path[i])
	{
		temp = ft_strjoin(data->path[i], data->cmd[0]);
		if (access(temp, X_OK) == 0)
		{
			free(data->cmd[0]);
			data->cmd[0] = ft_strdup(temp);
			free(temp);
			return ;
		}
		free(temp);
		i++;
	}
}

void	make_fork(t_path *data, char **envp)
{
	data->pid = fork();
	if (data->pid == 0)
	{
		access_path(data);
		if (data->cmd_flag)
			execve(data->o_cmd_split[0], data->o_cmd_split, envp);
		else
			execve(data->cmd[0], data->cmd, envp);
		printf("%s: command not found\n", data->o_cmd_split[0]);
	}
	else
		waitpid(data->pid, NULL, 0);
}
