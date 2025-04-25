/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/25 20:05:07 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

void	ft_env(t_data *minishell, char **cmd, t_token *start)
{
	int	i;

	i = 0;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	if (!cmd[1])
	{
		while (minishell->env[i])
		{
			printf("%s\n", minishell->env[i]);
			i++;
		}
	}
	return ;
}

void	ft_echo(t_data *minishell, char **cmd, t_token *start)
{
	int	i;
	int	flag;

	i = 1;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	if (cmd[i])
		flag = echo_flag_check(cmd[i]);
	else
	{
		printf("\n");
		return ;
	}
	if (flag)
		i++;
	echo_print(cmd, i, flag);
}

void	ft_cd(t_data *minishell, char **cmd, t_token *start)
{
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	if (cmd[1] && !cmd[2])
	{
		if (chdir(cmd[1]) == 0)
			return ;
		else if (access(cmd[1], F_OK) == -1)
			write (2, "cd: No such file or directory\n", 30);
		else
			write(2, "cd: Permission denied\n", 22);
	}
	else if (!cmd[1])
	{
		if (chdir("/home/jaejo") == 0)
			return ;
	}
	else
		write (2, "cd: too many arguments\n", 23);
	minishell->exit_code = 1;
	return ;
}

void	ft_pwd(t_data *minishell, char **cmd, t_token *start)
{
	char	*now;
	int		i;

	i = 0;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	while (cmd[i])
		i++;
	if (i > 1)
	{
		minishell->exit_code = 2;
		if (cmd[1][0] != '-')
			write (2, "pwd: too many arguments\n", 25);
		else
			write (2, "pwd: invalid option\n", 20);
		return ;
	}
	now = getcwd(NULL, 0);
	if (now)
		printf("%s\n", now);
	free(now);
}
