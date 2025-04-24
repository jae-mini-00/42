/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/24 18:51:48 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

// static void	terminal_state(int store_flag)
// {
// 	static struct termios	old;
// 	static struct termios	new;

// 	if (store_flag)
// 	{
// 		tcgetattr(STDIN_FILENO, &old);
// 		ft_memcpy(&new, &old, sizeof(struct termios));
// 		new.c_lflag &= ~ICANON;
// 		new.c_cc[VMIN] = 1;
// 		new.c_cc[VTIME] = 0;
// 		tcsetattr(STDIN_FILENO, TCSANOW, &new);
// 	}
// 	else
// 		tcsetattr(STDIN_FILENO, TCSANOW, &old);
// }

static void	ctrl_c(int fd, int pipe[2], int *status)
{
	dup2(fd, 0);
	close(pipe[0]);
	*status = 1;
}

static void	here_doc_trance(t_token *token, int fd)
{
	token->type = REDIRECTION;
	free(token->value);
	token->value = ft_strdup("<");
	free(token->next->value);
	token->next->value = NULL;
	token->next->fd = fd;
}

static void	minishell_here_doc(t_token *token, int *status)
{
	char		*temp;
	char		*end;
	int			fd[2];
	const int	len = ft_strlen(token->next->value) + 1;
	const int	infd = dup(0);

	end = ft_strjoin(token->next->value, "\n");
	pipe(fd);
	while (1)
	{
		write(1, "> ", 2);
		temp = get_next_line(0);
		if (!temp)
			ctrl_c(infd, fd, status);
		if (*status == 1 || ft_strncmp(temp, end, len) == 0)
		{
			get_next_line(1023);
			here_doc_free(fd[1], infd, temp, end);
			if (*status != 1)
				here_doc_trance(token, fd[0]);
			return ;
		}
		write(fd[1], temp, ft_strlen(temp));
		free(temp);
	}
}

void	minishell_here_doc_check(t_data *minishell, int *status)
{
	t_token	*now;

	now = minishell->token;
	signal (SIGINT, sigint_handler);
	while (now && !*status)
	{
		*status = 0;
		if (now->type == HERE_DOC)
		{
			minishell->here_doc_count++;
			minishell_here_doc(now, status);
			now = now->next;
		}
		else
			now = now->next;
	}
	signal (SIGINT, print_signal);
}
