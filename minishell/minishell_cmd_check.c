/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cmd_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:34:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/27 20:34:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	path_cmd(t_path *data)
{
	char	**path_cmd;
	int		i;

	i = 0;
	while (data->cmd[i])
		i++;
	i--;
	path_cmd = ft_split(data->cmd[i], ' ');
	split_free(data->cmd);
	data->cmd = path_cmd;
}

void	cmd_check(t_path *data, char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (cmd[i] == '.' || cmd[i] == '~' || cmd[i] == '/')
	{
		data->cmd_flag = 1;
		data->cmd = ft_split(cmd, '/');
		data->o_cmd_split = ft_split(cmd, ' ');
		path_cmd(data);
	}
	else if (cmd[i] == '\n' || cmd[i] == '\0')
	{
		data->cmd_flag = 0;
		data->cmd = NULL;
		data->o_cmd_split = NULL;
	}
	else
	{
		data->cmd_flag = 0;
		data->cmd = ft_split(cmd, ' ');
		data->o_cmd_split = ft_split(cmd, ' ');
	}
}
