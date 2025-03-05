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
		printf("exit\n");
		if (minishell->o_cmd_split[1] && minishell->o_cmd_split[2])
			printf("exit: Too many arguments\n");
		else if (minishell->o_cmd_split[1] && !minishell->o_cmd_split[2])
			printf("exit: Argument '%s' is not a valid integer\n", \
					minishell->o_cmd_split[1]);
		minishell_free(minishell);
		exit(0);
	}
	else if (!ft_strncmp(minishell->o_cmd_split[0], "cd", 3))
	{
		ft_cd(minishell->o_cmd_split);
		minishell->builtin_flag = 1;
	}
}

void	builtin_check(t_data *minishell)
{
	int		i;
	char	**temp;

	minishell->builtin_flag = 0;
	temp = ft_split(minishell->o_cmd_split[0], '/');
	i = split_last(temp);
	if (!ft_strncmp(temp[i], "env", 4))
		ft_env(minishell);
	else if (!ft_strncmp(temp[i], "echo", 5))
	{
		ft_echo(minishell);
		minishell->builtin_flag = 1;
	}
	/*else if (!ft_strncmp(temp[i], "pwd", 4))
	{
		ft_pwd(minishell);
		minishell->builtin_flag = 1;
	}*/
	split_free(temp);
	builtin_check2(minishell);
}

int	echo_flag_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 'n')
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
