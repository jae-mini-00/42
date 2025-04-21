/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_run.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/22 02:28:19 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_RUN_H
# define MINISHELL_RUN_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../builtin/minishell_builtin.h" 
# include "../signal/minishell_signal.h" 

/* fork */
int		io_dup(t_token *start, int std_in, int std_out, int status);
void	solo_fork(t_data *minishell);
void	multi_fork(t_data *minishell, int cmd_size, int i);

/* fork utils */
char	**make_execve_cmd(t_token *start);
void	multi_fork_dup(int **fd);
void	token_fd_close(t_token *start, int mode);
void	dup_capsule(int std, int mode, t_token *start, int *status);
t_token	*find_start(t_token *token);

/* run */
void	minishell_run(t_data *minishell);

/* prompt */
char	*make_prompt(char *av, char **envp);

/* here_doc */
void	minishell_here_doc_check(t_data *minishellm, int *status);

/* pipe */
int		**fd_init(void);
void	all_fd_close(int **fd);
void	pipe_dup(int **fd, int i);
void	pipe_open_close(int **fd, int i, int cmd_size);

#endif
