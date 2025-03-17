/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/03/17 18:56:07 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FORK_H
# define MINISHELL_FORK_H

# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"

/* token */
t_token	*token_init(char *str, t_data *minishell);

/* minishell token data */
char	**minishell_token_data(char *str);

/* minishell_split */
char	**minishell_split(char const *str);

#endif
