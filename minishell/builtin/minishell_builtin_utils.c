/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:28:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/15 20:59:47 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

int	split_last(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i - 1);
}
void	echo_print(char **cmd, int i, int flag)
{
	while (cmd[i])
	{
		if (cmd[i + 1])
			printf("%s ", cmd[i]);
		else if (!flag)
			printf("%s\n", cmd[i]);
		else
			printf("%s", cmd[i]);
		i++;
	}
}
int	builtin_type_check(t_token *token)
{
	t_token *temp;

	temp = token;
	while (temp)
	{
		if (temp->type == BUILTIN)
			return (true);
		temp = temp->next;
	}
	return (false);
}

int	echo_flag_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 'n')
		i++;
	else
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}