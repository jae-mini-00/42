/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/18 15:04:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static int	space_plus_len(char *str)
{
	char	quote;
	int		flag;
	int		i;

	i = 0;
	flag = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (!quote && (str[i] == '|' || (str[i] == '>'  && str[i + 1] != '>') || 
			(str[i] == '<' && str[i + 1] != '<')))
			flag++;
		i++;
	}
	if (quote)
		return (0);
	return (i + flag * 2 + 1);
}

static char	*space_plus_str_copy(char *str, int i, int j, char quote)
{
	char	*new_str;
	int		len;

	len = space_plus_len(str);
	new_str = (char *)malloc(sizeof(char) * len);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (!quote && (str[i] == '|' || (str[i] == '>'  && str[i + 1] != '>') || 
			(str[i] == '<' && str[i + 1] != '<')))
		{
			new_str[j++] = ' ';
			new_str[j++] = str[i++];
			new_str[j++] = ' ';
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}
char	**minishell_token_data(char *str)
{
	int		i;
	char	*new_str;
	char	quote;
	char	**split;

	quote = 0;
	i = space_plus_len(str);
	if (!i)
		return (ft_split(str, ' '));
	new_str = space_plus_str_copy(str, 0, 0, quote);
	split = token_split(new_str);
	free(new_str);
	return (split);
}
