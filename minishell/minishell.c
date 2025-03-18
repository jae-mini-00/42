/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/18 18:33:51 by jaejo            ###   ########.fr       */
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
	while (1)
	{
		minishell.prompt = make_prompt(av[1]);
		minishell.o_cmd = readline(minishell.prompt);
		o_cmd_split_init(&minishell);
		/*if (minishell.token != NULL)
		{
			// printf("run\n");
			minishell_run(&minishell)
		}*/
		t_token *temp = minishell.token;
		while (temp)
		{
			printf("value :%s type :%s\n", minishell.token->value, get_type_string(minishell.token->type));
			temp = temp->next;
		}
		add_history(minishell.o_cmd);
		minishell_free(&minishell);
	}
	split_free(minishell.env);
	rl_clear_history();
}
/*
		t_token *temp = minishell.token;
		while (temp)
		{
			printf("value :%s type :%s\n", minishell.token->value, get_type_string(minishell.token->type));
			temp = temp->next;
		}
*/
