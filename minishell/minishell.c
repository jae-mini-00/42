/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/24 20:28:55 by jaejo            ###   ########.fr       */
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

static void	minishell_printf(void)
{
	printf("\033[1;31m___ \033[0;33m ___ \033[1;33m_  _\033[1;32m   _  _\033");
	printf("[1;36m            ____ \033[1;34m _\033");
	printf("[1;35m            _  _ \033[0m\n");
	printf("\033[1;31m|  \\/\033[0;33m  |(\033[1;33m_)\033[1;32m| \\ | |\033");
	printf("[1;36m(_)         \033[1;34m / ___|\033");
	printf("[1;35m| |         \033[0;35m | || |\033[0m\n");
	printf("\033[1;31m| .  . \033[0;33m| _\033");
	printf("[1;33m |  \\| |\033[1;32m _         \033");
	printf("[1;36m  \\`--.\033[1;34m | |__   \033");
	printf("[1;35m ___\033[0;35m | || |\033[0m\n");
	printf("\033[1;31m| |\\/| \033[0;33m|| |\033");
	printf("[1;33m| . ` |\033[1;32m| |         \033");
	printf("[1;36m  `--.\\\033[1;34m| '_ \\ \033");
	printf("[1;35m / _ \\\033[0;35m| || |\033[0m\n");
	printf("\033[1;31m| |  | \033[0;33m|| |\033");
	printf("[1;33m| |\\  |\033[1;32m| |        \033");
	printf("[1;36m /\\__/ /\033[1;34m| | | |\033");
	printf("[1;35m|  __/\033[0;35m| || |\033[0m\n");
	printf("\033[1;31m\\_|  |_/\033[0;33m|_|\033[1;33m\\_| \033[1;32m\\_/\033");
	printf("[1;36m|_|        \033[1;34m \\____/\033");
	printf("[1;35m |_| |_|\033[0;35m \\___|\033[0;35m|_||_|\033[0m\n");
	printf("\n\n\n\n\n\n\n\n\n");
}

int	main(int ac, char **av, char **envp)
{
	t_data	minishell;

	if (ac > 3)
		return (0);
	minishell_printf();
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
	rl_clear_history();
}
