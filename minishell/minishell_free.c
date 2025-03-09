/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:41:03 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 22:27:52 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_free(t_data *minishell)
{
	free(minishell->now);
	free(minishell->o_cmd);
	split_free(minishell->env);
	split_free(minishell->path);
	split_free(minishell->o_cmd_split);
}

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
