/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 21:38:44 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

static char	*get_env_name(char *env)
{
	int	i;
	int	len;
	char	*env_name;

	i = 0;
	len = env_len(env);
	if (env[len] != '=')
		return (NULL); 
	env_name = (char *)malloc(sizeof(char) * (len + 2));
	if (!env_name)
		return (NULL);
	while (i <= len)
	{
		env_name[i] = env[i];
		i++;
	}
	env_name[i] = '\0';
	return (env_name);
}

void	ft_export(t_data *minishell, char **cmd)
{
	int		i;
	int		len;
	char	*env_name;
	
	i = 0;
	io_dup (minishell->token, 0, 1);
	if (!cmd[1])
		while (minishell->env[i])
			printf("declare -x %s\n", minishell->env[i++]);
	else
	{
		env_name = get_env_name(cmd[1]);
		if (!env_name)
			return ;
		len = ft_strlen(env_name);
		while (ft_strncmp(minishell->env[i], env_name, len) != 0)
			i++;
		if (minishell->env[i])
			change_env(minishell, cmd[1], i);
		else
			make_env(minishell, cmd[1]);
		free(env_name);
	}
}

void	ft_unset(t_data *minishell, char **cmd)
{
	int	i;
	int	len;
	char	*env_name;

	i = 0;
	io_dup (minishell->token, 0, 1);
	if (!cmd[1])
		return ;
	env_name = ft_strjoin(cmd[1], "=");
	len = ft_strlen(env_name);
	while (minishell->env[i])
	{
		if (ft_strncmp(minishell->env[i], env_name, len) == 0)
			break ;
		i++;
	}
	if (minishell->env[i])
		remove_minishell_env(minishell, env_name, len);
	free(env_name);
}
