/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/23 18:19:20 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static int	space_plus_len(char *str, int str_len)
{
	char	quote;
	int		flag;
	int		i;

	i = -1;
	flag = 10;
	quote = 0;
	while (str[++i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (!quote && (str[i] == '|'))
			flag++;
		else if (!quote && i > 0 && i + 1 < str_len)
		{
			if ((str[i - 1] != '>' && str[i] == '>' && str[i + 1] != '>') \
				|| (str[i - 1] != '<' && str[i] == '<' && str[i + 1] != '<'))
				flag++;
		}
	}
	if (quote)
		return (0);
	return (i + flag * 2 + 1);
}

static int	redirection_plus_len(char *str, int str_len)
{
	char	quote;
	int		flag;
	int		i;

	i = -1;
	flag = 10;
	quote = 0;
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		flag++;
	while (str[++i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (!quote && i > 0 && i + 1 < str_len)
		{
			if ((str[i - 1] == '>' && str[i] == '>' && str[i + 1] != '>') || \
			(str[i - 1] == '<' && str[i] == '<' && str[i + 1] != '<'))
				flag++;
		}
	}
	if (quote)
		return (0);
	return (i + flag * 2 + 1);
}

static char	*space_plus_str_copy(char *str, int i, int j, char quote)
{
	char	*new_str;

	new_str = ft_calloc(sizeof(char), space_plus_len(str, ft_strlen(str)));
	if (!new_str)
		return (NULL);
	if ((str[0] == '<' && str[1] != '<') || (str[0] == '>' && str[1] != '>'))
		redirection_copy(new_str, str, &j, &i);
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if ((i > 0 && (str[i] == '|' || (str[i - 1] != '>' && str[i] == '>' && \
			str[i + 1] != '>') || (str[i - 1] != '<' && str[i] == '<' \
			&& str[i + 1] != '<')) && !quote))
			redirection_copy(new_str, str, &j, &i);
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}

static char	*redirection_space(char *str, int i, int j, char quote)
{
	char	*new_str;

	new_str = ft_calloc(sizeof(char), \
		redirection_plus_len(str, ft_strlen(str)));
	if (!new_str)
		return (NULL);
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		redirection_copy2(new_str, str, &j, &i);
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '"'))
			quote = str[i];
		else if (quote == str[i])
			quote = 0;
		if (i > 0 && ((str[i - 1] != '>' && str[i] == '>' && str[i + 1] == '>') \
			|| (str[i - 1] != '<' && str[i] == '<' && str[i + 1] == '<')) \
			&& !quote)
			redirection_copy2(new_str, str, &j, &i);
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
	char	*temp;
	char	**split;

	i = space_plus_len(str, ft_strlen(str));
	if (!i)
		return (ft_split(str, ' '));
	temp = space_plus_str_copy(str, 0, 0, 0);
	new_str = redirection_space(temp, 0, 0, 0);
	split = token_split(new_str);
	free(new_str);
	free(temp);
	return (split);
}
