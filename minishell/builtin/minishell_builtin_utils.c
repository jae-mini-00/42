/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:28:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/14 00:22:48 by jaejo            ###   ########.fr       */
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
void	echo_print(t_data *minishell, int i, int flag)
{
	while (minishell->o_cmd_split[i])
	{
		if (minishell->o_cmd_split[i + 1])
			printf("%s ", minishell-> o_cmd_split[i]);
		else if (!flag)
			printf("%s\n", minishell->o_cmd_split[i]);
		else
			printf("%s", minishell->o_cmd_split[i]);
		i++;
	}
}
int	builtin_type_check(t_token *token)
{
	t_token *temp;
	char	**cmd;

	temp = token;
	while (temp)
	{
		if (temp->type == BUILTIN)
			return (true);
		temp = temp->next;
	}
	return (0);
}