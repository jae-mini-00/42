/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:07:29 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/15 21:27:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

static void	builtin_check3(t_data *minishell)
{
	(void)minishell;
	// if (!ft_strncmp(minishell->o_cmd_split[0], "export", 7))
	// {
	// 	ft_export(minishell);
	// 	minishell->builtin_flag = 1;
	// }
}

static void	builtin_check2(t_data *minishell, char **cmd)
{
	if (!ft_strncmp(cmd[0], "exit", 5))
	{
		printf("exit\n");
		if (cmd[1] && cmd[2])
			printf("exit: Too many arguments\n");
		else if (cmd[1] && !cmd[2])
			printf("exit: Argument '%s' is not a valid integer\n", cmd[1]);
		split_free(cmd);
		minishell_free(minishell);
		exit(0);
	}
	else if (!ft_strncmp(cmd[0], "cd", 3))
		ft_cd(minishell, cmd);
	else
		builtin_check3(minishell);
}

void	builtin_check(t_data *minishell)
{
	char		**cmd;
	const int	in = dup(0);
	const int	out = dup(1);

	cmd = make_execve_cmd(minishell->token);
	if (!ft_strncmp(cmd[0], "env", 4) && !cmd[1])
		ft_env(minishell, cmd);
	else if (!ft_strncmp(cmd[0], "echo", 5))
		ft_echo(minishell, cmd);
	else if (!ft_strncmp(cmd[0], "pwd", 4))
		ft_pwd(minishell, cmd);
	else
		builtin_check2(minishell, cmd);
	split_free(cmd);
	dup2(in, 0);
	dup2(out, 1);
}

