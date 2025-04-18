/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/18 21:36:21 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include "../pharsing/minishell_pharsing.h"
# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../signal/minishell_signal.h"
# include "../run/minishell_run.h"  


/* builtin utils */
int		ft_str_isdigit(char *str);
int     echo_flag_check(char *str);
int		builtin_type_check(t_token *token);
void	echo_print(char **cmd, int i, int flag);

/* builtin check */
void	builtin_check(t_data *minishell);

/* builtin */
void	ft_cd(t_data *minishell, char **cmd);
void	ft_pwd(t_data *minishell, char **cmd);
void	ft_env(t_data *minishell, char **cmd);
void	ft_echo(t_data *minishell, char **cmd);

/* export unset */
void	ft_unset(t_data *minishell, char **cmd);

/* export unset utils */
void	make_env(t_data *minishell, char *env);
void	change_env(t_data *minishell, char *env, int i);
void	remove_minishell_env(t_data *minishell, char *env_name, int len);

#endif
