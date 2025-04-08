/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/09 02:29:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	solo_fork(t_data *minishell)
{
	char **cmd;

	cmd = make_execve_cmd(minishell->token);
	minishell->pid = fork();
	if (minishell->pid == 0)
	{
		io_dup (minishell->token, 0, 1);
		execve(cmd[0], cmd, minishell->env);
		printf ("%s: command not found\n", cmd[0]);
		split_free(cmd);
		exit_free(minishell);
	}
}
void	multi_fork(t_data *minishell)
{
	t_token *temp;
	char **cmd;
	int fd[2][2];

	pipe(fd[0]);
	fd[1][0] = -1;
	fd[1][1] = -1;
	temp = minishell->token;
	while (temp)
	{
		multi_fork_dup(*fd[2]);
		minishell->pid = fork();
		cmd = make_execve_cmd(temp);
		if (minishell->pid == 0)
		{
			io_dup (minishell->token, 0, 1);
			execve(cmd[0], cmd, minishell->env);
			printf ("%s: command not found\n", cmd[0]);
			split_free(cmd);
			exit_free(minishell);
		}
		else
			temp = find_start(temp);
	}
	(void)minishell;
}
