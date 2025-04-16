/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:28:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 22:20:46 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

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
int	ft_str_isdigit(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i])
		return (false);
	else
		return (true);
}