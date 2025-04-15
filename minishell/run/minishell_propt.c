/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_propt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/15 23:00:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_run.h"

static char	*make_seet(char **envp)
{
	char	*seet;
	int		len;
	int		j;
	int		i;

	j = 0;
	i = -1;
	len = ft_strlen("SESSION_MANAGER=local/");
	while (envp[++i])
		if (ft_strncmp("SESSION_MANAGER=local/", envp[i], len) == 0)
			break;
	if (!envp[i])
		return (ft_strdup(""));
	while (envp[i][len + j] != '.')
		j++;
	seet = (char *)malloc(sizeof(char) * j + 1);
	if (!seet)
		return (ft_strdup(""));
	seet[j] = '\0';
	while (--j >= 0)
		seet[j] = envp[i][len + j];
	return (seet);
}

static char	*make_user(char *av, char **envp)
{
	char 	*user;
	char 	*seet;
	char	*temp;

	seet = make_seet(envp);
	temp = ft_strjoin(av, "@");
	user = ft_strjoin(temp, seet);
	free(temp);
	free(seet);
	temp = ft_strjoin(user, ":");
	free(user);
	return (temp);
}

static char	*prompt_getcwd(void)
{
	char	*cwd;
	char	*temp;
	int		i;

	i = -1;
	temp = NULL;
	cwd = getcwd(NULL, 0);
	if (ft_strncmp(cwd, "/home/jaejo", 11) == 0)
	{
		temp = (char *)malloc(sizeof(char) * \
			(ft_strlen(cwd) + 1 - 11 + 1));
		if (!temp)
			return (cwd);
		temp[0] = '~';
		while (cwd[11 + (++i)])
			temp[1 + i] = cwd[11 + i];
		temp[1 + i] = '\0';
		free(cwd);
		return (temp);
	}
	return (cwd);
}

char	*make_prompt(char *av, char **envp)
{
	char	*user;
	char	*seet;
	char	*temp;
	char	*prompt;

	if (av)
		user = make_user(av, envp);
	else
		user = make_user("jaejo", envp);
	temp = prompt_getcwd();
	seet = ft_strjoin(temp, "$ ");
	prompt = ft_strjoin(user, seet);
	free(user);
	free(temp);
	free(seet);
	return (prompt);
}
