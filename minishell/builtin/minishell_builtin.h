/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/15 21:00:14 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../signal/minishell_signal.h"
# include "../run/minishell_run.h"  


/* builtin utils */
int		builtin_type_check(t_token *token);
int     echo_flag_check(char *str);
void	echo_print(char **cmd, int i, int flag);

/* builtin check */
void	builtin_check(t_data *minishell);

/* builtin */
void	ft_env(t_data *minishell, char **cmd);
void	ft_echo(t_data *minishell, char **cmd);
void	ft_pwd(t_data *minishell, char **cmd);
void	ft_cd(t_data *minishell, char **cmd);

#endif
