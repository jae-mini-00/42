/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/17 18:25:42 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// o_cmd_split 자리에 token을 가지고 char **로 데이터 만들어서 바꾸기

void	make_fork(t_data *minishell)
{
	if (access(minishell->o_cmd_split[0], X_OK) == 0)
	{
		minishell->pid = fork();
		if (minishell->pid == 0)
		{
			execve(minishell->o_cmd_split[0], minishell->o_cmd_split, minishell->env);
			if (minishell->o_cmd_split[2])
				printf ("cd: Too many args for cd command\n");
			else
				printf ("%s: No such file or directory\n", \
						minishell->o_cmd_split[0]);
		}
		else
			waitpid(minishell->pid, NULL, 0);
	}
	else
		printf ("%s: command not found\n", minishell->o_cmd_split[0]);
}
