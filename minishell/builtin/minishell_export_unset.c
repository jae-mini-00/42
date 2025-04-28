/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/29 06:34:27 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

static char	*get_env_name(char *env)
{
	int		i;
	int		len;
	char	*env_name;

	i = -1;
	len = env_len(env);
	if (len == -1)
	{
		write (2, "export:'", 9);
		write (2, env, ft_strlen(env));
		write (2, "': not a valid identifier\n", 27);
		return (NULL);
	}
	if ((env[len] != '=' && env[len] != '+') || \
		(env[len] == '+' && env[len + 1] != '='))
		return (NULL);
	env_name = (char *)malloc(sizeof(char) * (len + 2));
	if (!env_name)
		return (NULL);
	while (++i < len)
		env_name[i] = env[i];
	env_name[i++] = '=';
	env_name[i] = '\0';
	return (env_name);
}

static void	export_printf(char **env, char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
	{
		while (env[i])
			printf("declare -x %s\n", env[i++]);
	}
}

static void	export_run(t_data *minishell, char **cmd, int i)
{
	char	*env_name;
	int		len;
	int		j;

	j = -1;
	env_name = get_env_name(cmd[i]);
	if (!env_name)
	{
		minishell->exit_code = 1;
		return ;
	}
	len = ft_strlen(env_name);
	while (minishell->env[++j])
		if (ft_strncmp(minishell->env[j], env_name, len) == 0)
			break ;
	if (minishell->env[j])
		change_env(minishell, cmd[i], j);
	else
		make_env(minishell, cmd[i]);
	free(env_name);
	if (minishell->exit_code != 1)
		minishell->exit_code = 0;
}

void	ft_export(t_data *minishell, char **cmd, t_token *start)
{
	int		i;

	i = -1;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
	export_printf(minishell->env, cmd[1]);
	i = 1;
	minishell->exit_code = 0;
	while (cmd[i])
	{
		export_run(minishell, cmd, i);
		i++;
	}
}

void	ft_unset(t_data *minishell, char **cmd, t_token *start)
{
	int		i;
	int		len;
	char	*env_name;

	i = 0;
	if (!start)
		io_dup (minishell->token, 0, 1, 0);
	else
		io_dup (start, 0, 1, 0);
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
	minishell->exit_code = 0;
}
