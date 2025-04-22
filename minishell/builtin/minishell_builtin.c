/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/22 18:17:22 by jaejo            ###   ########.fr       */
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
			printf("cd: %s: No such file or directory\n", cmd[1]);
		else
			printf("cd: %s: Permission denied\n", cmd[1]);
	}
	else if (!cmd[1])
	{
		if (chdir("/home/jaejo") == 0)
			return ;
	}
	else
		printf("cd: too many arguments\n");
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
		if (cmd[1][0] != '-')
			printf("pwd: too many arguments\n");
		else
			printf("pwd: %s: invalid option\n", cmd[1]);
		return ;
	}
	now = getcwd(NULL, 0);
	if (now)
		printf("%s\n", now);
	free(now);
}
