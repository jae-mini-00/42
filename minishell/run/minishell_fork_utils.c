/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 02:06:17 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static int	cmd_size(t_token *token)
{
	int	count;

	count = 0;
	while (token && token->type != PIPE)
	{
		if (token->type != REDIRECTION && token->type != IO_FILE)
			count++;
		token = token->next;
	}
	return (count);
}

void	token_fd_close(t_token *start, int mode)
{
	if (mode == 2)
	{
		start = find_start(start);
		mode = 1;
	}
	while (start && (start->type != PIPE || mode == 1))
	{
		if (start->fd != -1)
		{
			close(start->fd);
			start->fd = -1;
		}
		start = start->next;
	}
}

t_token	*find_start(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp && temp->type != PIPE)
		temp = temp->next;
	if (temp)
		return (temp->next);
	return (temp);
}

char	**make_execve_cmd(t_token *start)
{
	int		i;
	t_token	*temp;
	char	**cmd;

	i = cmd_size(start);
	temp = start;
	cmd = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cmd)
		return (NULL);
	cmd[i] = NULL;
	i = 0;
	while (temp && temp->type != PIPE)
	{
		if (temp->type != REDIRECTION && temp->type != IO_FILE)
		{
			cmd[i] = ft_strdup(temp->value);
			i++;
		}
		temp = temp->next;
	}
	return (cmd);
}

void	io_dup(t_token *start, int std_in, int std_out)
{
	int	fd;

	while (start && start->type != PIPE)
	{
		if (start->type == REDIRECTION)
		{
			if (ft_strncmp(start->value, ">", 2) == 0)
			{
				fd = open(start->next->value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
				dup2(fd, std_out);
			}
			else if (ft_strncmp(start->value, "<", 2) == 0)
			{
				if (start->next->fd == -1)
					fd = open(start->next->value, O_CREAT | O_RDONLY, 0644);
				else
				{
					fd = start->next->fd;
					start->next->fd = -1;
				}
				dup2(fd, std_in);
			}
			else if (ft_strncmp(start->value, ">>", 3) == 0)
			{
				fd = open(start->next->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
				dup2(fd, std_out);
			}
			close(fd);
		}
		start = start->next;
	}
}
