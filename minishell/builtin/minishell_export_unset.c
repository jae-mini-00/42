/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_export_unset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 07:07:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/16 18:53:35 by jaejo            ###   ########.fr       */
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
	else
		make_env(minishell);
}