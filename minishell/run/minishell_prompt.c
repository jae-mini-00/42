/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:57:05 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/19 22:03:21 by jaejo            ###   ########.fr       */
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
			break ;
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
	char	*user;
	char	*seet;
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

static	char	*color_prompt(char *str, int mode, char *temp1)
{
	const char	*b_start = "\001\033[1;34m\002";
	const char	*b_end = "\001\033[0m\002 "; 
	const char	*g_start = "\001\033[1;32m\002";
	const char	*g_end = "\001\033[0m\002 ";
	char		*temp2;

	if (mode == 1)
	{
		temp1 = ft_strjoin(g_start, str);
		temp2 = ft_strjoin(temp1, g_end);
		free(temp1);
		return (temp2);
	}
	else
	{
		temp1 = ft_strjoin(b_start, str);
		temp2 = ft_strjoin(temp1, b_end);
		free(temp1);
		return (temp2);
	}
}

char	*make_prompt(char *av, char **envp)
{
	char	*user;
	char	*seet;
	char	*temp;
	char	*prompt;
	char	*temp1;

	temp1 = NULL;
	if (av)
		user = make_user(av, envp);
	else
		user = make_user("jaejo", envp);
	temp = prompt_getcwd();
	prompt = user;
	user = color_prompt(user, 1, temp1);
	free(prompt);
	prompt = temp;
	temp = color_prompt(temp, 0, temp1);
	free(prompt);
	seet = ft_strjoin(temp, "$ ");
	prompt = ft_strjoin(user, seet);
	free(user);
	free(temp);
	free(seet);
	return (prompt);
}
