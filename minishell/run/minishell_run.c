/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:38 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/23 18:44:03 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

char	**make_execve_cmd(t_token *start, t_token *end)
{
	int		i;
	t_token *temp;
	char	**cmd;

	i = 0;
	temp = start;
	while (temp != end)
	{
		temp = temp->next;
		i++;
	}
	cmd = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cmd)
		return (NULL);
	cmd[i] = NULL;
	i = 0;
	while (start != end)
	{
		cmd[i] = ft_strdup(start->value);
		i++;
		start = start->next;
	}
	return (cmd);
}
static int	check_pipe(t_data *minishell)
{
	t_token *temp;

	temp = minishell->token;
	while (temp)
	{
		if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	if (temp)
		return (true);
	return (false);
}
void	minishell_run(t_data *minishell)
{
	int check;

	//here_doc 처리 먼저
	check = check_pipe(minishell);
	if (check)
		multi_fork(minishell, minishell->token, NULL);
	else
		solo_fork(minishell, minishell->token, NULL);
	// else
	// 	builtin(minishell);
	if (minishell->pid)
	{
		signal (SIGINT, program_signal);
		waitpid(minishell->pid, NULL, 0);
		signal (SIGINT, print_signal);
	}
}
// void	minishell_run(t_data *minishell, t_token *start, t_token *end)
// {
// 	t_token *temp;
// 	char **cmd;

// 	temp = minishell->token;
// 	while (temp)
// 	{
// 		while (temp && temp->type != PIPE && temp->type != HERE_DOC && temp->type != REDIRECTION)
// 			temp = temp->next;
// 		end = temp;
// 		cmd = make_execve_cmd(start, end);
// 		make_fork(cmd, minishell);
// 		if (temp)
// 			temp = temp->next;
// 		start = temp;
// 		split_free(cmd);
// 	}
// }