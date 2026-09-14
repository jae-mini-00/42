/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:08:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/02 20:47:08 by jaejo            ###   ########.fr       */
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
		minishell->exit_code = 0;
	}
	else
	{
		write (2, "env: '", 7);
		write (2, cmd[2], ft_strlen(cmd[2]));
		write (2, "': No such file or directory\n", 30);
		minishell->exit_code = 1;
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
		flag = echo_flag_check(cmd);
	else
	{
		write (1, "\n", 1);
		return ;
	}
	if (flag)
		i = flag;
	echo_print(cmd, i, flag);
	minishell->exit_code = 0;
}

static int	cd_run(char **cmd, char *home)
{
	if (cmd[1] && !cmd[2])
	{
		if (chdir(cmd[1]) == 0)
			return (0);
		else if (access(cmd[1], F_OK) == -1 && cmd[1][0] != '-')
			write (2, "cd: No such file or directory\n", 30);
		else if (cmd[1][0] != '-')
			write(2, "cd: Permission denied\n", 22);
		else
			return (0);
	}
	else if (!cmd[1])
	{
		if (!home)
		{
			write (2, "cd: HOME not set\n", 18);
			return (1);
		}
		else
			chdir(home);
		return (0);
	}
	return (1);
}

void	ft_cd(t_data *minishell, char **cmd, t_token *start)
{
	char	*now;
	char	*temp;

	now = NULL;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	now = getcwd(NULL, 0);
	temp = minishell->old_pwd;
	minishell->exit_code = cd_run(cmd, minishell->home);
	if (cmd[1] && cmd[1][0] == '-')
	{
		printf("%s\n", minishell->old_pwd);
		chdir(minishell->old_pwd);
		minishell->exit_code = 0;
	}
	else if (minishell->exit_code == 1 && cmd[2])
		write (2, "cd: too many arguments\n", 23);
	minishell->old_pwd = ft_strdup(now);
	free(temp);
	free(now);
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
	minishell->exit_code = 0;
	free(now);
}
