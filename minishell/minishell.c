/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/13 22:45:26 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char *get_type_string(t_type type)
{
    switch (type)
    {
        case COMMAND: return "COMMAND";
        case BUILTIN: return "BUILTIN";
        case ARG: return "ARG";
        case REDIRECTION: return "REDIRECTION";
        case HERE_DOC: return "HERE_DOC";
        case PIPE: return "PIPE";
        case ENV: return "ENV";
		case IO_FILE: return "IO_FILE";
        default: return "UNKNOWN";
    }
}
int	main(int ac, char **av, char **envp)
{
	t_data	minishell;

	(void)av;
	if (ac > 2)
		return (0);
	minishell_init(&minishell, envp);
	signal (SIGINT, print_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		minishell.prompt = make_prompt(av[1]);
		minishell.o_cmd = readline(minishell.prompt);
		ctrl_d(&minishell);
		o_cmd_split_init(&minishell);
		if (minishell.token != NULL)
			minishell_run(&minishell);
		add_history(minishell.o_cmd);
		minishell_free(&minishell);
	}
	split_free(minishell.env);
	rl_clear_history();
}

		// minishell_run(&minishell);
		// t_token *temp = minishell.token;
		// while (temp)
		// {
		// 	printf("value :%s type :%s\n", temp->value, get_type_string(temp->type));
		// 	temp = temp->next;
		// }
