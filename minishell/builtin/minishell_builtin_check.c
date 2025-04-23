/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:07:29 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/23 21:00:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

static void	builtin_check3(t_data *minishell, char **cmd, t_token *start)
{
	if (!ft_strncmp(cmd[0], "export", 7))
		ft_export(minishell, cmd, start);
	else if (!ft_strncmp(cmd[0], "unset", 6))
		ft_unset(minishell, cmd, start);
}

static void	builtin_check2(t_data *minishell, char **cmd, t_token *start)
{
	int	i;

	if (!ft_strncmp(cmd[0], "exit", 5))
	{
		printf("exit\n");
		if (cmd[1] && cmd[2])
			printf("exit: Too many arguments\n");
		else if (cmd[1] && !ft_str_isdigit(cmd[1]) && !cmd[2])
			printf("exit: Argument '%s' is not a valid integer\n", cmd[1]);
		if (cmd[1] && ft_str_isdigit(cmd[1]))
		{
			i = ft_atoi(cmd[1]);
			if (i != 0)
			{
				split_free(cmd);
				exit_free(minishell, i);
			}
		}
		split_free(cmd);
		exit_free(minishell, minishell->exit_code);
	}
	else if (!ft_strncmp(cmd[0], "cd", 3))
		ft_cd(minishell, cmd, start);
	else
		builtin_check3(minishell, cmd, start);
}

void	builtin_check(t_data *minishell)
{
	char		**cmd;
	const int	in = dup(0);
	const int	out = dup(1);

	cmd = make_execve_cmd(minishell->token);
	if (!ft_strncmp(cmd[0], "env", 4) && !cmd[1])
		ft_env(minishell, cmd, NULL);
	else if (!ft_strncmp(cmd[0], "echo", 5))
		ft_echo(minishell, cmd, NULL);
	else if (!ft_strncmp(cmd[0], "pwd", 4))
		ft_pwd(minishell, cmd, NULL);
	else
		builtin_check2(minishell, cmd, NULL);
	split_free(cmd);
	dup2(in, 0);
	dup2(out, 1);
}

int	pipe_builtin_check(char *cmd)
{
	if (!ft_strncmp(cmd, "env", 4))
		return (true);
	else if (!ft_strncmp(cmd, "echo", 5))
		return (true);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (true);
	else if (!ft_strncmp(cmd, "exit", 5))
		return (true);
	else if (!ft_strncmp(cmd, "cd", 3))
		return (true);
	else if (!ft_strncmp(cmd, "export", 7))
		return (true);
	else if (!ft_strncmp(cmd, "unset", 6))
		return (true);
	return (false);
}

void	pipe_builtin_run(t_data *minishell, char **pipe_cmd, t_token *start)
{
	if (!ft_strncmp(pipe_cmd[0], "env", 4) && !pipe_cmd[1])
		ft_env(minishell, pipe_cmd, start);
	else if (!ft_strncmp(pipe_cmd[0], "echo", 5))
		ft_echo(minishell, pipe_cmd, start);
	else if (!ft_strncmp(pipe_cmd[0], "pwd", 4))
		ft_pwd(minishell, pipe_cmd, start);
	else
		builtin_check2(minishell, pipe_cmd, start);
}
