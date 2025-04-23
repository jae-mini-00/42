/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/23 22:14:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_signal.h"

void	print_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	sigint_handler(int sig)
{
	(void)sig;
	close(0);
	write(1, "\n", 1);
}

void	program_start(void)
{
	signal (SIGINT, print_signal);
	signal(SIGQUIT, SIG_IGN);
}

void	program_return(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, 0);
}

void	ctrl_d(t_data *minishell)
{
	if (!minishell->o_cmd)
	{
		exit_free(minishell, 0);
		printf("exit\n");
		exit (minishell->exit_code);
	}
}
