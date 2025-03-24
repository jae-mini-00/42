/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variable_expansion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/24 17:13:53 by jaejo            ###   ########.fr       */
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
	while (env[++j])
		if (ft_strncmp(env[j], temp, ft_strlen(temp)) == 0)
			need_env = ft_strdup(&env[j][ft_strlen(temp) + 1]);
	if (need_env)
		env_init(token, start, need_env, 0);
	else
		remove_env(token, start);
	free(env);
	free(temp);
}
static void	value_check(t_token *token, char **env, int i, char quote)
{
	while (token->value[i])
	{
		if (token->value[i] == '$')
		{
			my_getenv(token, &token->value[i], env);
			i = 0;
			continue ;
		}
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
		value_check(temp, minishell->env, 0 , 0);
		if (temp->type == ENV)
			temp->type = ARG;
		temp = temp->next;
	}
	token_check(minishell);
}
// static void	minishell_conversion_env(t_token *data, char **env, int len)
// {
// 	char	*temp;
// 	int 	i;

// 	i = 0;
// 	temp = (char *)malloc(sizeof(char) * len);
// 	if (!temp)
// 		return ;
// 	while (env[i])
// 	{
// 		if (ft_strncmp(&temp[1], env[i], ft_strlen(&temp[1])) == 0)
// 		{
// 			free(data->value);
// 			data->value = ft_strdup(env[i] + ft_strlen(&temp[1]));
// 			free(temp);
// 			data->type = ARG;
// 			return ;
// 		}
// 		i++;
// 	}
// 	data->type = REMOVE;
// 	free(temp);
// }
