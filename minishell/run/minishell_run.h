/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/06 22:55:13 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_RUN_H
# define MINISHELL_RUN_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../signal/minishell_signal.h" 

/* fork */
void	solo_fork(t_data *minishell, t_token *start, t_token *end);
void	multi_fork(t_data *minishell, t_token *start, t_token *end);

/* fork utils */
char	**make_execve_cmd(t_token *start, t_token *end);

/* run */
void	minishell_run(t_data *minishell);

/* prompt */
char	*make_prompt(char *av);

/* here_doc */
void	minishell_here_doc_check(t_data *minishell);

/* dup */


#endif
