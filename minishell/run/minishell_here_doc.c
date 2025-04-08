/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/09 01:20:44 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static char	*fd_name(int count)
{
	char	*name;

	name = ft_strjoin("temp", ft_itoa(count));
	return (name);
}
static void	here_doc_trance(t_token *token, char *name)
{
	token->type = REDIRECTION;
	free(token->value);
	token->value = ft_strdup("<");
	free(token->next->value);
	token->next->value = name; 
}
static void	minishell_here_doc(t_token *token, char *name)
{
	char	*temp;
	char	*end;
	int		fd;
	int		len;

	end = ft_strjoin(token->next->value, "\n");
	len = ft_strlen(end);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 6044);
	while (1)
	{
		write(1, "> ", 2);
		temp = get_next_line(0);
		if (signal_condition == 1 || temp == NULL || ft_strncmp(temp, end, len) == 0)
		{
			free(temp);
			free(end);
			here_doc_trance(token, name);
			close(fd);
			return ;
		}
		write(fd, temp, ft_strlen(temp));
		free(temp);
	}
}
void	minishell_here_doc_check(t_data *minishell)
{
	t_token *now;
	
	now = minishell->token;
	signal (SIGINT, here_doc_signal); // 수정 해야함
	while (now && signal_condition == 0)
	{
		if (now->type == HERE_DOC)
		{
			minishell->here_doc_count++;
			minishell_here_doc(now, fd_name(minishell->here_doc_count));
			now = now->next;
		}
		else 
			now = now->next;
	}
	signal (SIGINT, print_signal); // 수정 해야함
}
