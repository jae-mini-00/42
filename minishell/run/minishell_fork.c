/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/21 21:14:50 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	make_fork(char **cmd, t_data *minishell)
{
	if (access(cmd[0], X_OK) == 0)
	{
		minishell->pid = fork();
		if (minishell->pid == 0)
		{
			execve(cmd[0], cmd, minishell->env);
			exit_free(minishell);
			split_free(cmd);
		}
		else
			waitpid(minishell->pid, NULL, 0);
	}
	else
		printf ("%s: command not found\n", cmd[0]);
}
