/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variable expansion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:48:41 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/17 22:08:41 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_pharsing.h"

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
		if (ft_strncmp(temp, env[i], ft_strlen(temp)) == 0)
		{
			free(temp);
			free(now->value);
			now->value = env[i];
			return ;
		}
		i++;
	}
	free(temp);
	free(now->value);
}
static void	value_check(char *data, char **env, int i, int j)
{
	char	quoite;

	quoite = 0;
	while (data[i])
	{
		if (!quoite && data[i] == '$')
			my_getenv(data, &data[i], env);
		else if (data[i] == '\'')
		{
			quoite = data[i++];
			while (data[i] && data[i] != quoite)
				i++;
			quoite = 0;
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
			minishell_conversion_env(token, minishell->env);
		else
			value_check(temp->value, minishell->env, 0, 0);
		temp = temp->next;
	}
}
