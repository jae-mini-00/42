/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:07:29 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:52:25 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	builtin_check2(t_data *minishell)
{
	if (!ft_strncmp(minishell->o_cmd_split[0], "exit", 5))
	{
		if (minishell->o_cmd_split[1] && minishell->o_cmd_split[2])
			printf("exit: Too many arguments\n");
		else if (minishell->o_cmd_split[1] && !minishell->o_cmd_split[2])
			printf("exit: Argument '%s' is not a valid integer\n", \
					minishell->o_cmd_split[1]);
		else
			exit(0);
		minishell->builtin_flag = 1;
	}
}

void	builtin_check(t_data *minishell)
{
	if (!ft_strncmp(minishell->o_cmd_split[0], "env", 4) && \
		!minishell->o_cmd_split[1])
	{
		minishell->builtin_flag = 1;
		ft_env(minishell->env);
	}
	else if (!ft_strncmp(minishell->o_cmd_split[0], "echo", 5) || \
		(minishell->o_cmd_split[1] && \
		!ft_strncmp(minishell->o_cmd_split[1], "echo", 5)))
	{
		if (minishell->o_cmd_split[1] && \
			!ft_strncmp(minishell->o_cmd_split[1], "echo", 5))
			ft_echo(&minishell->o_cmd_split[1]);
		else
			ft_echo(minishell->o_cmd_split);
		minishell->builtin_flag = 1;
	}
	builtin_check2(minishell);
}

int	echo_flag_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	else
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
