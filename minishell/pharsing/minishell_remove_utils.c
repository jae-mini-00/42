/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_remove_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:22:31 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/30 19:13:33 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

int	check_quite(char *value)
{
	int		i;
	int		flag;
	char	quite;

	i = 0;
	flag = 0;
	quite = '\0';
	if (!value)
		return (flag);
	while (value[i])
	{
		if (!quite && (value[i] == '\'' || value[i] == '"'))
			quite = value[i];
		else if (quite && quite == value[i])
		{
			flag++;
			quite = '\0';
		}
		i++;
	}
	return (flag);
}

char	*new_value(char *value, int flag, int i, int j)
{
	char	*new_value;
	char	quite;

	quite = '\0';
	new_value = (char *)malloc(sizeof(char) * \
							(ft_strlen(value) - (flag * 2) + 1));
	if (!new_value)
		return (NULL);
	while (value[i])
	{
		if (!quite && (value[i] == '\'' || value[i] == '"'))
			quite = value[i++];
		else if (quite && quite == value[i])
		{
			quite = '\0';
			i++;
		}
		else
			new_value[j++] = value[i++];
	}
	new_value[j] = '\0';
	return (new_value);
}

void	remove_quite(t_token *token)
{
	int		flag;
	char	*temp;

	flag = 0;
	while (token)
	{
		flag = check_quite(token->value);
		if (!flag)
			token = token->next;
		else
		{
			token->quite_flag = 1;
			temp = token->value;
			token->value = new_value(token->value, flag, 0, 0);
			free(temp);
			token = token->next;
		}
	}
}

void	o_remove_quite(t_token *token)
{
	int		flag;
	char	*temp;

	flag = 0;
	while (token)
	{
		flag = check_quite(token->o_value);
		if (!flag)
			token = token->next;
		else
		{
			temp = token->o_value;
			token->o_value = new_value(token->o_value, flag, 0, 0);
			free(temp);
			token = token->next;
		}
	}
}
