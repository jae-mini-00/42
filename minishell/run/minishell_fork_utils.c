/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/09 01:17:36 by jaejo            ###   ########.fr       */
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
t_token	*find_start(t_token *token)
{
	t_token *temp;
	
	temp = token;
	while (temp && temp->type != PIPE)
		temp = temp->next;
	if (temp)
		return(temp->next);
	return(temp);
}
char	**make_execve_cmd(t_token *start)
{
	int		i;
	t_token *temp;
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
				fd = open(start->next->value, O_CREAT | O_WRONLY, 0644);
				dup2(fd, std_out);
				close(fd);
			}			
			else
			{
				fd = open(start->next->value, O_CREAT | O_RDONLY, 0644);
				dup2(fd, std_in);
				close(fd);
			}
		}
		start = start->next;
	}
}
// void multi_fork_dup(int fd[2][2])
// {
// 	if (fd[1][1] == -1)
// 	{
// 		dup2(fd[0][0], 0);
// 		close(fd[0][0]);
// 		fd[0][0] = -1;
// 	}
// 	else if (fd[0][1] != -1)
// 	{
// 		pipe(fd[1]);
// 		dup2(fd[0][1], 0);
// 		dup2(fd[1][0], 1);
// 		close(fd[0][1]);
// 		close(fd[1][0]);
// 		fd[0][1] = -1;
// 		fd[1][0] = -1;
// 	}
// 	else if (fd[1][1] != -1)
// 	{
// 		pipe(fd[0]);
// 		dup2(fd[1][1], 0);
// 		dup2(fd[0][0], 1);
// 		close(fd[0][0]);
// 		close(fd[1][1]);
// 		fd[0][0] = -1;
// 		fd[1][1] = -1;
// 	}
// 	else if(fd[0][1] == -1)
// 	{
// 		dup2(fd[1][1], 1);
// 		close(fd[1][1]);
// 		fd[1][1] = -1;
// 	}
// }
