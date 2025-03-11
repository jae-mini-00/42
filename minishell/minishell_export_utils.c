/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/11 07:07:22 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	dot_check(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '"')
			flag++;
		i++;
	}
	return (flag);
}

char	*remove_export(char *str)
{
	int	i;
	int	j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	temp = malloc(sizeof(char) * (ft_strlen(&str[i]) + 1));
	while (str[i + j])
	{
		temp[j] = str[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*remove_dot(char *str)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	i = 0;
	temp = malloc(sizeof(char) * (ft_strlen(str) - dot_check(str) + 1));
	while (str[i + j])
	{
		if (str[i + j] == '"')
			j++;
		temp[i] = str[i + j];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	path_export(t_data *minishell)
{
	int		i;
	char	*save;
	char	*temp;
	char	**new_env;

	i = 0;
	new_env = (char **)malloc(sizeof(char *) * (split_last(minishell->env) + 2));
	temp = remove_export(minishell->o_cmd);
	save = remove_dot(temp);
	free(temp);
	while (minishell->env[i])
	{
		new_env[i] = ft_strdup(minishell->env[i]);
		i++;
	}
	new_env[i++] = save;
	new_env[i] = NULL;
	split_free(minishell->env);
	minishell->env = new_env;
}

void	make_env(t_data *minishell)
{
	if (dot_check(minishell->o_cmd) == 2 && ft_strchr(minishell->o_cmd, '='))
		path_export(minishell);
	else
		printf("export: '%s': not a valid identifier\n", minishell->o_cmd_split[1]);
}
