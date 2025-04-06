/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/06 22:53:50 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static int	check_pipe(t_data *minishell)
{
	t_token *temp;

	temp = minishell->token;
	while (temp)
	{
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	if (temp)
		return (true);
	return (false);
}
void	minishell_run(t_data *minishell)
{
	int check;

	minishell_here_doc_check(minishell);
	check = check_pipe(minishell);
	if (check)
		multi_fork(minishell, minishell->token, NULL);
	else
		solo_fork(minishell, minishell->token, NULL);
	// // else
	// // 	builtin(minishell);
	// if (minishell->pid)
	// {
	// 	signal (SIGINT, program_signal);
	// 	waitpid(minishell->pid, NULL, 0);
	// 	signal (SIGINT, print_signal);
	// }
}
