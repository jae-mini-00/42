/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_phasing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/24 17:14:39 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

int	env_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && ((str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') ||
	(str[i] == '_')))
	i++;
	return (i);
}
void	remove_token(t_data *minishell, t_token *data)
{
	t_token *now;
	t_token *prev;

	if (!minishell || !minishell->token || !data)
		return;
	now = minishell->token;
	prev = NULL;
	if (now == data)
	{
		minishell->token = now->next;
		free(now->value);
		free(now);
		return;
	}
	while (now && now != data)
	{
		prev = now;
		now = now->next;
	}
	if (!now)
		return;
	prev->next = now->next;
	free(now->value);
	free(now);
}

void	remove_env(t_token *token, char *start)
{
	char	*temp;
	char	*now_value;
	int		i;
	
	i = 0;
	now_value = token->value;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(token->value) - env_len(&start[1]) + 2));
	if (!temp)
		return ;
	while (*now_value)
	{
		if (now_value == start)
			now_value = now_value + env_len(&start[1]) + 1;
		if (*now_value)
			temp[i++] = *now_value++;
	}
	temp[i] = '\0';
	free(token->value);
	token->value = temp;
}
void	token_check(t_data *minishell)
{
	t_token	*temp;
	t_token	*next_token;

	while (minishell->token && minishell->token->type == REMOVE)
	{
		temp = minishell->token;
		minishell->token = temp->next;
		remove_token(minishell, temp);
	}
	temp = minishell->token;
	while (temp && temp->next)
	{
		next_token = temp->next;
		if (next_token->type == REMOVE)
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
