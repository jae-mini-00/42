/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 22:01:23 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_builtin.h"

void	ft_export(t_data *minishell, char **cmd)
{
	int		i;
	
	i = 0;
	io_dup (minishell->token, 0, 1);
	if (!cmd[1])
		while (minishell->env[i])
			printf("declare -x %s\n", minishell->env[i++]);
	// else
	// 	make_env(minishell);
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
