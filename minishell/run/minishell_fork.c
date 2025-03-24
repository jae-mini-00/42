/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/24 13:37:41 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	solo_fork(t_data *minishell, t_token *start, t_token *end)
{
	t_token *temp;
	char **cmd;

	temp = minishell->token;
	while (temp && temp->type != HERE_DOC && temp->type != REDIRECTION)
		temp = temp->next;
	end = temp;
	cmd = make_execve_cmd(start, end);
	minishell->pid = fork();
	if (minishell->pid == 0)
	{
		//dup 작업(분기)
		execve(cmd[0], cmd, minishell->env);
		printf ("%s: command not found\n", cmd[0]);
		split_free(cmd);
		exit_free(minishell);
	}
}
void	multi_fork(t_data *minishell, t_token *start, t_token *end)
{
	// t_token *temp;
	// char **cmd;
	// int	fd[2];
	
	// temp = minishell->token;
	// while (temp && temp->type != HERE_DOC && temp->type != REDIRECTION)
	// {

	// }
	(void)minishell;
	(void)start;
	(void)end;
	return ;
}
