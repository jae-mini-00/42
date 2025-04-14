/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_phasing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/05 18:25:11 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

int	env_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] >= 'a' && str[i] <= 'z') || \
	(str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && \
		str[i] <= '9') || (str[i] == '_')))
	{
		i++;
	}
	return (i);
}

void	redirection_copy(char *new_str, char *str, int *j, int *i)
{
	int	idx;
	int	j_idx;

	idx = *i;
	j_idx = *j;
	new_str[j_idx++] = ' ';
	new_str[j_idx++] = str[idx++];
	new_str[j_idx++] = ' ';
	*i = idx;
	*j = j_idx;
}

void	token_check(t_data *minishell)
{
	t_token	*temp;
	t_token	*next_token;

	while (minishell->token && \
		(minishell->token->type == REMOVE || !minishell->token->value[0]))
	{
		temp = minishell->token;
		minishell->token = temp->next;
		remove_token(minishell, temp);
	}
	temp = minishell->token;
	while (temp && temp->next)
	{
		next_token = temp->next;
		if (next_token->type == REMOVE || !next_token->value[0])
		{
			temp->next = next_token->next;
			remove_token(minishell, next_token);
		}
		else
			temp = temp->next;
	}
}

void	type_trance(t_token *token, t_data *minishell, int flag)
{
	while (token)
	{
		if (token->type == HERE_DOC || token->type == REDIRECTION)
		{
			if (token->next && token->next->type == ARG)
				token->next->type = IO_FILE;
		}
		else if (token->type == ARG && !flag)
		{
			if (token->type == ARG)
			{
				flag = type_init(&token->value, minishell);
				if (flag == 2)
					token->type = COMMAND;
				else if (flag == 1)
					token->type = BUILTIN;
			}
		}
		else if (token->type == PIPE)
			flag = 0;
		token = token->next;
	}
}
