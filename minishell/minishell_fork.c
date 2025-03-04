/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 22:43:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_fork(t_data *minishell, char **envp)
{
	if (access(minishell->o_cmd_split[0], X_OK) == 0)
	{
		minishell->pid = fork();
		if (minishell->pid == 0)
		{
			execve(minishell->o_cmd_split[0], minishell->o_cmd_split, envp);
			if (minishell->o_cmd_split[2])
				printf ("cd: Too many args for cd command\n");
			else
				printf ("%s: No such file or directory\n", minishell->o_cmd_split[0]);
			//minishell_free(minishell);
		}
		else
			waitpid(minishell->pid, NULL, 0);
	}
	else
		printf ("%s: command not found\n", minishell->o_cmd_split[0]);
}