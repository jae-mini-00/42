/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/22 02:26:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_type_string(t_type type)
{
	static char	*type_strings[] = \
	{
		"COMMAND",
		"BUILTIN",
		"ARG",
		"REDIRECTION",
		"HERE_DOC",
		"PIPE",
		"ENV",
		"REMOVE",
		"IO_FILE"
	};

	return (type_strings[type]);
}

static void	pharsing_check(t_token *data, char **env)
{
	t_token	*temp;
	int		pid;
	char	*cmd[2];

	cmd[0] = "clear";
	cmd[1] = NULL;
	pid = fork();
	if (pid == 0)
	{
		execve("/usr/bin/clear", cmd, env);
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		temp = data;
		while (temp)
		{
			printf("value :%-30s | type :%s\n", temp->value, \
				get_type_string(temp->type));
			temp = temp->next;
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	minishell;

	if (ac > 3)
		return (0);
	minishell_init(&minishell, envp, av[2]);
	program_start();
	while (1)
	{
		minishell.prompt = make_prompt(av[1], envp);
		minishell.o_cmd = readline(minishell.prompt);
		ctrl_d(&minishell);
		o_cmd_split_init(&minishell);
		if (minishell.token != NULL && !minishell.mode)
			minishell_run(&minishell);
		else if (minishell.token != NULL && minishell.mode)
			pharsing_check(minishell.token, envp);
		add_history(minishell.o_cmd);
		minishell_free(&minishell);
	}
	split_free(minishell.env);
	rl_clear_history();
}
