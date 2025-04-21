/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/19 19:59:09 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./free/minishell_free.h"
# include "./pharsing/minishell_pharsing.h"
# include "./signal/minishell_signal.h"
# include "./run/minishell_run.h"
# include "./builtin/minishell_builtin.h"

/* init */
void	minishell_init(t_data *minishell, char **envp, char *av);
void	o_cmd_split_init(t_data *minishell);

#endif
