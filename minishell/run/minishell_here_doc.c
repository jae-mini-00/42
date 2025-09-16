/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/01 02:00:30 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static void	ctrl_c(int fd, int pipe[2], int *status)
{
	dup2(fd, 0);
	if (signal_c(-1) == 130)
		close(pipe[0]);
	else
		write (1, "expected 'limit', got EOF\n", 27);
	*status = 1;
}

static void	here_doc_trance(t_token *token, int fd, int *status)
{
	if (signal_c(-1) != 130)
		*status = 0;
	token->type = REDIRECTION;
	free(token->value);
	token->value = ft_strdup("<");
	free(token->next->value);
	token->next->value = NULL;
	token->next->fd = fd;
}

static void	minishell_here_doc(t_token *token, int *status, char **env)
{
	char		*temp;
	int			fd[2];
	const int	infd = dup(0);

	pipe(fd);
	while (1)
	{
		temp = readline("> ");
		if (!temp)
			ctrl_c(infd, fd, status);
		if (*status == 1 || here_doc_write(env, fd[1], temp, token->next))
		{
			here_doc_free(fd[1], infd, temp);
			if (*status != 1 || signal_c(-1) != 130)
				here_doc_trance(token, fd[0], status);
			return ;
		}
	}
}

void	minishell_here_doc_check(t_data *minishell, int *status, char **env)
{
	t_token	*now;

	now = minishell->token;
	signal_c(0);
	signal (SIGINT, sigint_handler);
	while (now && !*status)
	{
		*status = 0;
		if (now->type == HERE_DOC)
		{
			minishell->here_doc_count++;
			minishell_here_doc(now, status, env);
			now = now->next;
		}
		else
			now = now->next;
	}
	signal (SIGINT, print_signal);
}
