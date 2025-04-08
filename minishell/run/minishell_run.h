/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/09 01:14:17 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_RUN_H
# define MINISHELL_RUN_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../signal/minishell_signal.h" 

/* fork */
void	solo_fork(t_data *minishell);
void	multi_fork(t_data *minishell);

/* fork utils */
char	**make_execve_cmd(t_token *start);
t_token	*find_start(t_token *token);
void	io_dup(t_token *start, int std_in, int std_out);
void	multi_fork_dup(int **fd);

/* run */
void	minishell_run(t_data *minishell);

/* prompt */
char	*make_prompt(char *av);

/* here_doc */
void	minishell_here_doc_check(t_data *minishell);

/* dup */


#endif
