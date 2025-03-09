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

static char	*make_prompt(char *av)
{
	char	*now;
	char	*user;
	char	*temp;
	char	*prompt;

	if (av)
		user = ft_strjoin(av, ":");
	else
		user = "jaejo:";
	temp = getcwd(NULL, 0);
	if (!ft_strncmp(temp, "/home/jaejo", 12))
	{
		free(temp);
		temp = "~/";
	}
	now = ft_strjoin(temp, "$ ");
	prompt = ft_strjoin(user, now);
	if (av)
		free(user);
	if (ft_strncmp(temp, "~/", 3))
		free(temp);
	free(now);
	return (prompt);
}

int	main(int ac, char **av, char **envp)
{
	t_data	minishell;

	(void)av;
	if (ac > 2)
		return (0);
	minishell_init(&minishell, envp);
	while (1)
	{
		minishell.now = make_prompt(av[1]);
		minishell.o_cmd = readline(minishell.now);
		o_cmd_split_init(&minishell);
		if (minishell.o_cmd_split != NULL && !minishell.builtin_flag)
		{
			//printf("fork\n");
			make_fork(&minishell, envp);
		}
		add_history(minishell.o_cmd);
		split_free(minishell.o_cmd_split);
		free(minishell.o_cmd);
		free(minishell.now);
	}
	rl_clear_history();
	split_free(minishell.path);
}
