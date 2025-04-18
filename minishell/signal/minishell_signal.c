/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 22:06:37 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_signal.h"

int	g_signal_condition;

void	print_signal(int sig)
{
	(void)sig;
	printf("\n");
	if (rl_on_new_line() == 0)
	{
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	here_doc_signal(int sig)
{
	(void)sig;
	g_signal_condition = 1;
}

void	program_signal(int sig)
{
	(void)sig;
	printf("\n");
}

void	ctrl_d(t_data *minishell)
{
	if (!minishell->o_cmd)
	{
		exit_free(minishell, 0);
		printf("exit\n");
		exit (0);
	}
}
