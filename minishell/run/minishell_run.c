/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/21 21:13:38 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

char	**make_execve_cmd(t_token *start, t_token *end)
{
	int		i;
	t_token *temp;
	char	**cmd;

	i = 0;
	temp = start;
	while (temp != end)
	{
		temp = temp->next;
		i++;
	}
	cmd = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cmd)
		return (NULL);
	cmd[i] = NULL;
	i = 0;
	while (start != end)
	{
		cmd[i] = ft_strdup(start->value);
		i++;
		start = start->next;
	}
	return (cmd);
}
void	minishell_run(t_data *minishell)
{
	t_token *start;
	t_token *end;
	t_token *temp;
	char **cmd;

	end = NULL;
	start = minishell->token;
	temp = minishell->token;
	if (temp)
	{
		while (temp && temp->type != PIPE && temp->type != HERE_DOC && temp->type != REDIRECTION)
			temp = temp->next;
		end = temp;
		if (temp)
			temp = temp->next;
		cmd = make_execve_cmd(start, end);
		start = temp;
		make_fork(cmd, minishell);
		split_free(cmd);
	}
}
