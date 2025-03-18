/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_phasing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/18 22:22:18 by jaejo            ###   ########.fr       */
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
	t_token *temp;

	temp = NULL;
	now = minishell->token;
	if (now == data)
	{
		free(now->value);
		free(now);
		minishell->token = NULL;
		return ;
	}
	while (now->next != data)
		now = now->next;
	if (now->next->next)
		temp = now->next->next;
	free(now->next->value);
	free(now->next);
	now->next = temp;
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
