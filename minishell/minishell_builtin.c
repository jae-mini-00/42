/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:43:30 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *minishell)
{
	int	i;

	i = 0;
	if (!minishell->o_cmd_split[1])
	{
		minishell->builtin_flag = 1;
		while (minishell->env[i])
		{
			printf("%s\n", minishell->env[i]);
			i++;
		}
	}
	return ;
}

void	ft_echo(t_data *minishell)
{
	int	i;
	int	flag;

	i = 1;
	if (access(minishell->o_cmd_split[0], X_OK) == 0)
	{
		if (minishell->o_cmd_split[i])
			flag = echo_flag_check(minishell->o_cmd_split[i]);
		else
		{
			printf("\n");
			return ;
		}
		if (flag)
			i++;
		echo_print(minishell, i, flag);
	}
	else
		printf("%s: No such file or directory\n", minishell->o_cmd_split[0]);
}

void	ft_cd(char **data)
{
	if (data[1] && !data[2])
	{
		if (chdir(data[1]) == 0)
			return ;
		else
			printf("cd: %s: No such file or directory\n", data[1]);
	}
	else if (!data[1])
	{
		if (chdir("home") == 0)
			return ;
	}
	else
		printf("cd: too many arguments\n");
	return ;
}
