/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:27 by jaejo             #+#    #+#             */
/*   Updated: 2025/04/22 19:22:52 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNAL_H
# define MINISHELL_SIGNAL_H

# include <signal.h>
# include <termios.h>
# include "../ft_printf/ft_printf.h"
# include "../free/minishell_free.h"

/* signal */
void	program_start(void);
void	program_return(void);
void	print_signal(int sig);
void	sigint_handler(int sig);
void	ctrl_d(t_data *minishell);

#endif
