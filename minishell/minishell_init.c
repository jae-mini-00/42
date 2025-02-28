/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:29:58 by jaejo             #+#    #+#             */
/*   Updated: 2025/02/27 16:29:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_full_path_split(char **path_split)
{
	int	i;
	char	*temp;

	i = 0;
	while (path_split[i])
	{
		temp = path_split[i];
		path_split[i] = ft_strjoin(path_split[i], "/");
		free(temp);
		i++;
	}
	return (path_split);
}

char	**path_init(char **envp)
{
	int	i;
	char *path;
	char **path_split;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
		{
			path = ft_strdup(envp[i] + 5);
			path_split = ft_split(path, ':');
			break ;
		}
		i++;
	}
	free(path);
	path_split = ft_full_path_split(path_split);
	return (path_split);
}
