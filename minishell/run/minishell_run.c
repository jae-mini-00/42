/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/23 20:55:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static int	check_pipe(t_token *data)
{
	t_token	*temp;
	int		flag;

	flag = 0;
	temp = data;
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

static int	syntax_err_check(t_token *data)
{
	t_token	*token;

	token = data;
	while (token)
	{
		if (token->type == REDIRECTION || token->type == HERE_DOC)
		{
			if (!token->next || \
				(token->next && (token->next->type == REDIRECTION \
				|| token->next->type == HERE_DOC || token->next->type == PIPE)))
			{
				write (2, "syntax error near unexpected token newline\n", 44);
				return (false);
			}
		}
		token = token->next;
	}
	if (check_pipe(data) == -1)
	{
		write (2, "syntax error near unexpected token newline\n", 44);
		return (false);
	}
	return (true);
}

static int	ft_exit_code(int status)
{
	if (WIFEXITED(status))
		return ((status >> 8) & 0xFF);
	else
		return (status + 128);
}

void	minishell_run(t_data *minishell)
{
	int	check;
	int	status;

	status = 0;
	if (syntax_err_check(minishell->token))
	{
		minishell_here_doc_check(minishell, &status);
		if (!status)
		{
			check = check_pipe(minishell->token);
			if (check)
				multi_fork(minishell, check + 1, 0);
			else if (builtin_type_check(minishell->token))
				builtin_check(minishell);
			else
				solo_fork(minishell);
			token_fd_close(minishell->token, 1);
			if (minishell->pid != 0)
				waitpid(minishell->pid, &status, 0);
			minishell->exit_code = ft_exit_code(status);
		}
	}
	else
		minishell->exit_code = 2;
}
