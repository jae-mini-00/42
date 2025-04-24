/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/24 21:30:21 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

void	ft_pid_free(t_data *minishell, int *status, int mode)
{
	int	i;

	i = 0;
	if (!minishell->pid)
		return ;
	while (minishell->pid[i] != -2 && mode == 1)
	{
		waitpid(minishell->pid[i], status, 0);
		i++;
	}
	free(minishell->pid);
	minishell->pid = NULL;
}

void	ft_malloc_pid(t_data *minishell, int size)
{
	minishell->pid = calloc(sizeof(pid_t), size + 1);
	if (!minishell->pid)
		return ;
	minishell->pid[size] = -2;
}
