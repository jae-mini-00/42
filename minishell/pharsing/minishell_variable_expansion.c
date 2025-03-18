/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variable_expansion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/18 23:16:03 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

void	env_init(t_token *token, char *start, char *env, int j)
{
	char	*temp;
	char	*copy;
	int		i;

	temp = (char *)malloc(sizeof(char) * (ft_strlen(token->value) + ft_strlen(env) - 
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
	free(env);
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
	i = env_len(&start[1]);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (!temp)
		return ;
	temp[i] = '\0';
	while (++j < i)
		temp[j] = start[1 + j];
	need_env = ft_strjoin(temp, "=");
	free(temp);
	temp = NULL;
	j = -1;
	while (env[++j])
		if (ft_strncmp(env[j], need_env, ft_strlen(need_env)) == 0)
			temp = ft_strdup(&env[j][ft_strlen(need_env)]);
	free(need_env);
	if (temp)
		env_init(token, start, temp, 0);
	else
		remove_env(token, start);
}
static void	minishell_conversion_env(t_token *data, char **env)
{
	t_token	*now;
	char	*temp;
	int 	i;

	i = 0;
	now = data;
	temp = ft_strjoin(now->value, "=");
	while (env[i])
	{
		if (ft_strncmp(&temp[1], env[i], ft_strlen(&temp[1])) == 0)
		{
			free(now->value);
			now->value = ft_strdup(env[i] + ft_strlen(&temp[1]));
			free(temp);
			now->type = ARG;
			return ;
		}
		i++;
	}
	now->type = REMOVE;
	free(temp);
}
static void	value_check(t_token *token, char **env, int i)
{
	char	quote;

	quote = 0;
	while (token->value[i])
	{
		if (!quote && token->value[i] == '$')
		{
			my_getenv(token, &token->value[i], env);
			i = 0;
		}
		else if (token->value[i] == '\'')
		{
			quote = token->value[i++];
			while (token->value[i] && token->value[i] != quote)
				i++;
			if (!token->value[i])
				return ;
			quote = 0;
		}
		i++;
	}
}
void	minishell_variable_expansion(t_token *token, t_data *minishell)
{
	t_token *temp;

	temp = token;
	while (temp)
	{
		if (temp->type == ENV)
			minishell_conversion_env(temp, minishell->env);
		else
			value_check(temp, minishell->env, 0);
		temp = temp->next;
	}
	token_check(minishell);
}
