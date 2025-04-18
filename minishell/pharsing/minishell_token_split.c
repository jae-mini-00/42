/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:07:25 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 19:02:15 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static int	ft_count(char const *s, int count, char quote)
{
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s && *s != ' ')
		{
			while (*s && *s != ' ')
			{
				if (*s == '"' || *s == '\'')
				{
					quote = *s++;
					while (*s && *s != quote)
						s++;
					if (!*s)
						return (-1);
					quote = 0;
				}
				s++;
			}
			count++;
		}
	}
	return (count);
}

static char	*ft_word_start(char const *s)
{
	while (*s && *s == ' ')
		s++;
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
		while (s[i] && s[i] != ' ')
		{
			if (s[i] == '"' || s[i] == '\'')
			{
				quote = s[i++];
				while (s[i] && s[i] != quote)
					i++;
			}
			i++;
		}
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
		while (*s && *s != ' ')
		{
			if (*s == '"' || *s == '\'')
			{
				quote = *s;
				temp[i++] = *s++;
				while (*s && *s != quote)
					temp[i++] = *s++;
			}
			temp[i++] = *s++;
		}
	}
	else
		return (NULL);
	return (temp);
}

char	**token_split(char const *s)
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
		s = ft_word_start(s);
		i = ft_len(s);
		temp[j] = word_copy(s, i, quote);
		s = s + i;
		j++;
	}
	return (temp);
}
