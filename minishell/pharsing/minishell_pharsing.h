/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pharsing.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/25 19:06:42 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PHARSING_H
# define MINISHELL_PHARSING_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"
# include "../signal/minishell_signal.h"

/* token init */
int		type_init(char **str, t_data *minishell);
int		type_init2(char **str, t_data *minishell);
t_token	*token_init(char *str);

/* minishell token data */
char	**minishell_token_data(char *str);

/* minishell token split */
char	**token_split(char const *str);

/* minishell variable expansion */
void	minishell_variable_expansion(t_token *token, t_data *minishell);

/* minishell variable exit code */
void	my_exit_code(t_token *token, char *start, t_data *minishell);

/* utils */
int		env_len(char *str);
void	token_check(t_data *minishell);
void	type_trance(t_token *token, t_data *minishell, int flag);
void	redirection_copy(char *new_str, char *str, int *j, int *i);
void	redirection_copy2(char *new_str, char *str, int *j, int *i);

/* minishell remove utils */
int		check_quite(char *value);
char	*new_value(char *value, int flag, int i, int j);
void	remove_quite(t_token *token);

#endif
