/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/14 00:21:33 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static int	check_pipe(t_data *minishell)
{
	t_token *temp;
	int		flag;

	flag = 0;
	temp = minishell->token;
	while (temp)
	{
		if (temp->type == PIPE && temp->next)
			flag++;
		if (temp->type == PIPE && !temp->next)
			return (-1);
		temp = temp->next;
	}
	return (flag);
}
void	minishell_run(t_data *minishell)
{
	int check;

	minishell_here_doc_check(minishell);
	check = check_pipe(minishell);
	if (check == -1)
		return ;
	if (check)
		multi_fork(minishell, check + 1, 0);
	// else if (builtin_type_check(minishell))
	// 	builtin_check(minishell);
	else
		solo_fork(minishell);
	if (minishell->pid != 0)
		waitpid(minishell->pid, NULL, 0);
}
