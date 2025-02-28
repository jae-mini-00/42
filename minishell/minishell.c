/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/27 15:57:08 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	t_path data;


	if (ac > 1)
		return (0);
	data.path = path_init(envp);
	(void)av;
	while (1)
	{
		data.o_cmd = readline("minishell> ");
		add_history(data.o_cmd);
		if (data.o_cmd)
		{
			cmd_check(&data, data.o_cmd);
			if (data.cmd)
				make_fork(&data, envp);
			free(data.o_cmd);
		}
	}
	rl_clear_history();
	split_free(data.path);
	split_free(data.cmd);
	return (0);
}
