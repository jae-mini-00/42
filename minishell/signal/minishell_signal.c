/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/19 22:42:16 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_signal.h"

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
void	ctrl_d(t_data *minishell)
{
	if (!minishell->o_cmd)
	{
		exit_free(minishell);
		printf("exit\n");
		exit (0);
	}
}
