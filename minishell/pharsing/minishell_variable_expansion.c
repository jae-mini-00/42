/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variable_expansion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/30 03:21:58 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

static void	remove_env(t_token *token, char *start)
{
	char	*temp;
	char	*now_value;
	int		i;

	i = 0;
	now_value = token->value;
	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(token->value) - env_len(&start[1])));
	if (!temp)
		return ;
	while (*now_value)
	{
		if (now_value == start)
			now_value = now_value + env_len(&start[1]) + 1;
		if (*now_value && now_value[0] != 0)
			temp[i++] = *now_value++;
	}
	temp[i] = '\0';
	free(token->value);
	token->value = temp;
}

static void	env_init(t_token *token, char *start, char *env, int j)
{
	char	*temp;
	char	*copy;
	int		i;

	temp = (char *)malloc(sizeof(char) * \
				(ft_strlen(token->value) + ft_strlen(env) - \
				env_len(start) + 1));
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
			copy = copy + env_len(start + 1) + 1;
		}
		if (*copy)
			temp[i++] = *copy++;
	}
	temp[i] = '\0';
	free(token->value);
	token->value = temp;
}

static void	my_getenv(t_token *token, char *start, char **env)
{
	char	*temp;
	char	*need_env;
	int		i;
	int		j;

	j = -1;
	need_env = NULL;
	i = env_len(&start[1]);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return ;
	temp[i] = '\0';
	while (++j < i)
		temp[j] = start[1 + j];
	j = -1;
	i = ft_strlen(temp);
	while (env[++j] && i)
		if (ft_strncmp(env[j], temp, ft_strlen(temp) + 1) == 61)
			need_env = ft_strdup(&env[j][i + 1]);
	if (need_env)
		env_init(token, start, need_env, 0);
	else
		remove_env(token, start);
	free(need_env);
	free(temp);
}

static char	*value_check(t_token *token, int i, char quote)
{
	while (token->value[i])
	{
		if (token->value[i] == '$' && token->value[i + 1])
			return (&token->value[i]);
		else if (!quote && token->value[i] == '"')
			quote = token->value[i];
		else if (quote && token->value[i] == '"')
			quote = 0;
		else if (!quote && token->value[i] == '\'')
		{
			quote = token->value[i++];
			while (token->value[i] && token->value[i] != quote)
				i++;
			if (!token->value[i])
				return (NULL);
			quote = 0;
		}
		i++;
	}
	return (NULL);
}

void	minishell_variable_expansion(t_token *token, t_data *minishell)
{
	t_token	*temp;
	char	*start;

	temp = token;
	while (temp)
	{
		start = value_check(temp, 0, 0);
		if (start)
		{
			if (start[1] != '?')
				my_getenv(temp, start, minishell->env);
			else
				my_exit_code(temp, start, minishell);
			temp->type = ARG;
		}
		else
			temp = temp->next;
	}
	remove_quite(token);
	token_check(minishell);
}
