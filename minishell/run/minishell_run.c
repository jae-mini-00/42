/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/29 21:27:45 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static int	check_pipe(t_token *data)
{
	t_token	*temp;
	int		flag;

	flag = 0;
	temp = data;
	if (temp->type == PIPE)
		return (-1);
	while (temp)
	{
		if (temp->type == PIPE && temp->next && temp->next->type != PIPE)
			flag++;
		if (temp->type == PIPE && (!temp->next || temp->next->type == PIPE))
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
			if (!token->next || (token->next && (token->next->type == \
				REDIRECTION || token->next->type == HERE_DOC || \
				token->next->type == PIPE || \
				token->next->value[0] == '>' || token->next->value[0] == '<')))
			{
				write (2, "syntax error\n", 13);
				return (false);
			}
		}
		token = token->next;
	}
	if (check_pipe(data) == -1)
	{
		write (2, "syntax error\n", 13);
		return (false);
	}
	return (true);
}

static int	ft_exit_code(int status)
{
	if (status == 131)
		write (1, "Quit (core dumped)\n", 20);
	else if (status == 2)
		write(1, "\n", 1);
	if (WIFEXITED(status))
	{
		signal_c((status >> 8) & 0xFF);
		return ((status >> 8) & 0xFF);
	}
	else
	{
		signal_c(WTERMSIG(status) + 128);
		return (WTERMSIG(status) + 128);
	}
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
			ft_pid_free(minishell, &status, 1);
			signal_c(minishell->exit_code);
			if (!builtin_type_check(minishell->token) || check)
				minishell->exit_code = ft_exit_code(status);
		}
	}
	else
		minishell->exit_code = 2;
}
