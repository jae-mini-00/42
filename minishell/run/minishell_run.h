/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/15 22:00:20 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_RUN_H
# define MINISHELL_RUN_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../builtin/minishell_builtin.h" 
# include "../signal/minishell_signal.h" 

/* fork */
void	solo_fork(t_data *minishell);
void	multi_fork(t_data *minishell, int cmd_size, int i);

/* fork utils */
char	**make_execve_cmd(t_token *start);
t_token	*find_start(t_token *token);
void	io_dup(t_token *start, int std_in, int std_out);
void	multi_fork_dup(int **fd);

/* run */
void	minishell_run(t_data *minishell);

/* prompt */
char	*make_prompt(char *av, char **envp);

/* here_doc */
void	minishell_here_doc_check(t_data *minishell);

/* pipe */
void	all_fd_close(int **fd);
int		**fd_init(void);
void	pipe_open_close(int **fd, int i, int cmd_size);
void	pipe_dup(int **fd, int i);

#endif
