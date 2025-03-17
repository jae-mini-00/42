/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/17 18:49:49 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./free/minishell_free.h"
# include "./pharsing/minishell_pharsing.h"

/* init */
void	minishell_init(t_data *minishell, char **envp);
void	o_cmd_split_init(t_data *minishell);

/* fork */
void	make_fork(t_data *minishell, char **envp);

/* check */
void	builtin_check(t_data *minishell);
int		echo_flag_check(char *str);

/* builtin
void	ft_env(t_data *minishell);
void	ft_echo(t_data *minishell);
void	ft_cd(char **data);
void	ft_pwd(char **data);
void	ft_export(t_data *minishell);

export utils 
void	make_env(t_data *minishell);

builtin utils 
int		split_last(char **split);
void	echo_print(t_data *minishell, int i, int flag);
*/

#endif
