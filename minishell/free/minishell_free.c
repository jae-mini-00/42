/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:41:03 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/19 20:44:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_free.h"

void	split_free(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
void	token_free(t_token *data)
{
	t_token	*temp;

	if (!data)
		return ;
	while (data)
	{
		temp = data;
		free(data->value);
		data = data->next;
		free(temp);
	}
}
void	minishell_free(t_data *minishell)
{
	free(minishell->prompt);
	free(minishell->o_cmd);
	split_free(minishell->path);
	token_free(minishell->token);
	minishell->prompt = NULL;
	minishell->o_cmd = NULL;
	minishell->path = NULL;
	minishell->token = NULL;
}
void	exit_free(t_data *minishell)
{
	if (minishell->prompt)
		free(minishell->prompt);
	if (minishell->o_cmd)
		free(minishell->o_cmd);
	if (minishell->env)
		split_free(minishell->env);
	if (minishell->path)
		split_free(minishell->path);
	if (minishell->token)
		token_free(minishell->token);
	minishell->prompt = NULL;
	minishell->o_cmd = NULL;
	minishell->path = NULL;
	minishell->token = NULL;
	minishell->env = NULL;
}
