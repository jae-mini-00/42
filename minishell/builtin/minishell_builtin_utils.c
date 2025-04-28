/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:28:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/29 04:44:27 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

void	echo_print(char **cmd, int i, int flag)
{
	while (cmd[i])
	{
		if (cmd[i + 1])
		{
			write (1, cmd[i], ft_strlen((const char *)cmd[i]));
			write (1, " ", 1);
		}
		else if (flag == 1)
		{
			write (1, cmd[i], ft_strlen((const char *)cmd[i]));
			write (1, "\n", 1);
		}
		else
			write (1, cmd[i], ft_strlen((const char *)cmd[i]));
		i++;
	}
}

int	builtin_type_check(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == BUILTIN)
			return (true);
		temp = temp->next;
	}
	return (false);
}

int	echo_flag_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[j])
	{
		i = 0;
		if (str[j][i] == '-' && str[j][i + 1] == 'n')
			i++;
		else
			return (j);
		while (str[j][i] == 'n')
			i++;
		if (str[j][i] == '\0')
			j++;
		else
			return (j);
	}
	return (j);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (false);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (false);
	else
		return (true);
}

void	exit_run(t_data *minishell, char **cmd)
{
	int	flag;

	flag = 0;
	write(2, "exit\n", 5);
	if (cmd[1] && !ft_str_isdigit(cmd[1]))
	{
		write(2, "bash: exit: ", 12);
		write(2, cmd[1], ft_strlen((const char *)cmd[1]));
		write (2, ": numeric argument required\n", 29);
		minishell->exit_code = 2;
	}
	else if (cmd[1] && cmd[2])
	{
		flag = 1;
		write(2, "bash: exit: too many arguments\n", 32);
		minishell->exit_code = 1;
	}
	else if (cmd[1])
		minishell->exit_code = ft_atoi(cmd[1]);
	if (!flag)
	{
		split_free(cmd);
		exit_free(minishell, minishell->exit_code);
	}
}
