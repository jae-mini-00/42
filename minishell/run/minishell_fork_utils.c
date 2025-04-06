/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/06 22:53:05 by jaejo            ###   ########.fr       */
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
