/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:50:25 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_data	minishell;

	(void)av;
	if (ac > 1)
		return (0);
	minishell_init(&minishell, envp);
	while (1)
	{
		minishell.o_cmd = readline("minishell> ");
		o_cmd_split_init(&minishell);
		if (minishell.o_cmd_split != NULL && !minishell.builtin_flag)
		{
			//printf("fork\n");
			make_fork(&minishell, envp);
		}
		add_history(minishell.o_cmd);
		split_free(minishell.o_cmd_split);
		free(minishell.o_cmd);
	}
	rl_clear_history();
	split_free(minishell.path);
}
