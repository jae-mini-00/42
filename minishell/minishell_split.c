/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:07:25 by jaejo             #+#    #+#             */
/*   Updated: 2024/10/15 21:04:12 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count(char const *s, int count, char quote)
{
	while (*s)
	{
		if (*s == ' ')
			s++;
		else
		{
			if (*s == '"' || *s == '\'')
			{
				quote = *s++;
				while (*s && *s != quote)
					s++;
				s++;
				quote = 0;
			}
			else
				while (*s && *s != ' ' && *s != '\'' && *s != '"')
					s++;
			count++;
		}
	}
	if (quote != 0)
		return (-1);
	return (count);
}

static char	*ft_word_start(char const *s, char *quote)
{
	while (*s && *s == ' ')
		s++;
	if (*s == '\'' || *s == '"')
		*quote = *s;
	else
		*quote = 0;
	return ((char *)s);
}

static int	ft_len(char const *s)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	if (*s)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = s[i++];
			while (s[i] && s[i] != quote)
				i++;
			i++;
		}
		else
			while (s[i] && s[i] != ' ' && s[i] != '\'' && s[i] != '"')
				i++;
	}
	return (i);
}

static char	*word_copy(char const *s, int i, char quote)
{
	char	*temp;

	temp = (char *)malloc (sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	temp[i] = '\0';
	i = 0;
	if (*s)
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			quote = *s;
			temp[i++] = *s++;
			while (*s && *s != quote)
				temp[i++] = *s++;
			temp[i++] = *s++;
		}
		else
			while (*s && *s != ' ' && *s != '\'' && *s != '"')
				temp[i++] = *s++;
	}
	else
		return (NULL);
	return (temp);
}

char	**minishell_split(char const *s)
{
	char	**temp;
	int		i;
	int		j;
	int		count;
	char	quote;

	j = 0;
	quote = 0;
	count = ft_count(s, 0, 0);
	if (count == -1)
		return (NULL);
	temp = (char **)malloc (sizeof(char *) * (count + 1));
	if (!temp)
		return (NULL);
	temp[count] = NULL;
	while (j < count)
	{
		s = ft_word_start(s, &quote);
		i = ft_len(s);
		temp[j] = word_copy(s, i, quote);
		s = s + i;
		j++;
	}
	return (temp);
}
