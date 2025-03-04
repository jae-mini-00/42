/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 23:07:29 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/04 23:52:25 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_check(t_data *minishell)
{
	if (ft_strncmp(minishell->o_cmd_split[0], "env", 4) == 0 && !minishell->o_cmd_split[1])
	{
		minishell->builtin_flag = 1;
		ft_env(minishell->env);
	}
}