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

void	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return ;
}

void	ft_echo(char **o_cmd_split)
{
	int	i;
	int	flag;

	i = 1;
	if (o_cmd_split[i])
		flag = echo_flag_check(o_cmd_split[i]);
	else
	{
		printf("\n");
		return ;
	}
	if (flag)
		i++;
	while (o_cmd_split[i])
	{
		if (o_cmd_split[i + 1])
			printf("%s ", o_cmd_split[i]);
		else if (!flag)
			printf("%s\n", o_cmd_split[i]);
		else
			printf("%s", o_cmd_split[i]);
		i++;
	}
}
