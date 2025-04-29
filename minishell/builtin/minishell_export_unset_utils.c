/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/29 21:45:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

void	change_env(t_data *minishell, char *env, int i, int *status)
{
	char	*temp;

	temp = NULL;
	if (*status != 1)
	{
		free(minishell->env[i]);
		minishell->env[i] = ft_strdup(env);
	}
	else
	{
		temp = ft_strjoin(minishell->env[i], &env[env_len(env) + 2]);
		free(minishell->env[i]);
		minishell->env[i] = temp;
	}
}

static int	split_size(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (i);
	while (split[i])
		i++;
	return (i);
}

static char	*remove_plus_env(char *env)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = NULL;
	temp = (char *)malloc(sizeof(char) * (ft_strlen(env)));
	if (!temp)
		return (NULL);
	while (env[i])
	{
		if (env[i] == '+')
			i++;
		temp[j++] = env[i++];
	}
	temp[j] = '\0';
	return (temp);
}

void	make_env(t_data *minishell, char *env, int *status)
{
	int		i;
	int		size;
	char	**new_env;

	i = 0;
	size = split_size(minishell->env);
	new_env = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_env)
		return ;
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	if (*status != 1)
		new_env[i++] = ft_strdup(env);
	else
		new_env[i++] = remove_plus_env(env);
	new_env[i] = NULL;
	split_free(minishell->env);
	minishell->env = new_env;
}

void	remove_minishell_env(t_data *minishell, char *env_name, int len)
{
	int		i;
	int		j;
	char	**new_env;

	j = 0;
	i = split_size(minishell->env);
	new_env = (char **)malloc(sizeof(char *) * i);
	if (!new_env)
		return ;
	new_env[i - 1] = NULL;
	i = 0;
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], env_name, len) == 0)
			i++;
		else
			new_env[j++] = ft_strdup(minishell->env[i++]);
	}
	split_free(minishell->env);
	minishell->env = new_env;
}
