/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/25 21:58:04 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_signal.h"

int	signal_c(int signal)
{
	static int	num = 0;

	if (signal != -1)
		num = signal;
	return (num);
}

void	print_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		signal_c(130);
	}
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

void	child_start(void)
{
	signal (SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
