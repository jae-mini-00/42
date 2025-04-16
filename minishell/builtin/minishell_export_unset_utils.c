/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 18:41:53 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

int	double_quote_check(char *str)
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

char	*remove_double_quote_export(char *str)
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
	temp = malloc(sizeof(char) * (ft_strlen(&str[i]) - 1));
	while (str[i + j])
	{
		if (str[i + j] == '"')
			i++;
		if (!str[i + j])
			break ;
		temp[j] = str[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*env_name(char *str)
{
	int	i;
	char	*name;

	i = 0;
	while (str[i] != '=')
		i++;
	name = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i++] = '=';
	name[i] = '\0';
	return (name);
}

void	path_export(t_data *minishell)
{
	int		i;
	char	*temp;
	char	*name;
	char	**new_env;

	i = -1;
	name = env_name(minishell->o_cmd_split[1]);
	new_env = (char **)malloc(sizeof(char *) * (split_last(minishell->env) + 3));
	temp = remove_double_quote_export(minishell->o_cmd);
	while (minishell->env[++i])
	{
		if (ft_strncmp(minishell->env[i], name, ft_strlen(name)))
			new_env[i] = ft_strdup(minishell->env[i]);
		else
		{
			new_env[i] = ft_strdup(temp);
			free(temp);
			temp = NULL;
		}
	}
	if (temp)
		new_env[i++] = temp;
	new_env[i] = NULL;
	split_free(minishell->env);
	minishell->env = new_env;
	free(name);
}

void	make_env(t_data *minishell, char **cmd)
{
	int	i;

	i = 0;
	while (minishell->o_cmd[i] != '=' && minishell->o_cmd[i])
		i++;
	if (!minishell->o_cmd[i])
		return ;
	if (minishell->o_cmd_split[1][0] >= '0' && minishell->o_cmd_split[1][0] <= '9')
		return ;
	if (minishell->o_cmd[i] == '=' && minishell->o_cmd[i + 1] == '"' \
		&& minishell->o_cmd[ft_strlen(minishell->o_cmd) - 1] == '"' && \
		double_quote_check(minishell->o_cmd) == 2)
		path_export(minishell);
	else
	{
		if (minishell->o_cmd_split[2])
			printf("export: '%s': not a valid identifier\n", minishell->o_cmd_split[2]);
		else	
			printf("export: '%s': not a valid identifier\n", minishell->o_cmd_split[1]);
	}
}
