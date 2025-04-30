/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_here_doc_exit_code.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/30 20:40:05 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

char	*here_doc_value_check(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1])
			return (&str[i]);
		i++;
	}
	return (NULL);
}

static char	*here_cod_exit_code_init(char *str, char *start, char *env, int j)
{
	char	*temp;
	char	*copy;
	int		i;

	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(str) + ft_strlen(env) - 1));
	if (!temp)
		return (NULL);
	i = 0;
	copy = str;
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
	return (temp);
}

char	*here_doc_exit_code(char *str, char *start)
{
	char	*temp;
	char	*new_value;

	temp = ft_itoa(signal_c(-1));
	new_value = here_cod_exit_code_init(str, start, temp, 0);
	free(temp);
	return (new_value);
}
