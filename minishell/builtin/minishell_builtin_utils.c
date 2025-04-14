/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:28:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/14 00:25:45 by jaejo            ###   ########.fr       */
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
	cmd = make_execve_cmd(token);
	//cmd 만들어서 cmd[0]배열을 split후 마지막 배열이 builtin 인지 확인 맞으면 true 아니면 false
	return (0);
}
