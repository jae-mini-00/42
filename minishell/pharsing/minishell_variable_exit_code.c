/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variable_exit_code.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/17 19:34:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static void	exit_code_init(t_token *token, char *start, char *env, int j)
{
	char	*temp;
	char	*copy;
	int		i;

	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(token->value) + ft_strlen(env) - 1));
	if (!temp)
		return ;
	i = 0;
	copy = token->value;
	while (*copy)
	{
		if (copy == start)
		{
			while (env[j])
				temp[i++] = env[j++];
			copy = copy + 2;
		}
		if (*copy)
			temp[i++] = *copy++;
	}
	temp[i] = '\0';
	free(token->value);
	token->value = temp;
}

void	my_exit_code(t_token *token, char *start, t_data *minishell)
{
	char	*temp;

	temp = ft_itoa(minishell->exit_code);
	exit_code_init(token, start, temp, 0);
	free(temp);
}
