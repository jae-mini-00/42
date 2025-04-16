/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:41:03 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 18:08:25 by jaejo            ###   ########.fr       */
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

void	exit_free(t_data *minishell, int num)
{
	free(minishell->prompt);
	free(minishell->o_cmd);
	split_free(minishell->env);
	split_free(minishell->path);
	token_free(minishell->token);
	minishell->prompt = NULL;
	minishell->o_cmd = NULL;
	minishell->path = NULL;
	minishell->token = NULL;
	minishell->env = NULL;
	if (num)
	{
		if (num == -1)
			exit (0);
		exit(num);
	}
}
