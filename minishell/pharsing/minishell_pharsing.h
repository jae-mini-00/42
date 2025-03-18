/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pharsing.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/18 22:22:40 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PHARSING_H
# define MINISHELL_PHARSING_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"

/* token */
t_token	*token_init(char *str, t_data *minishell);

/* minishell token data */
char	**minishell_token_data(char *str);

/* minishell token split */
char	**token_split(char const *str);

/* minishell variable expansion */
void	minishell_variable_expansion(t_token *token, t_data *minishell);

/* utils */
int		env_len(char *str);
void	remove_token(t_data *minishell, t_token *data);
void	remove_env(t_token *token, char *start);

#endif