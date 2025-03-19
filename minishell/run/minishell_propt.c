/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_propt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/19 22:16:17 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

char	*make_prompt(char *av)
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
