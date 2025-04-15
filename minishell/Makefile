# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2025/04/15 21:01:30 by jaejo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

NAME = minishell

FREE_SRCS = ./free/minishell_free.c \

SIGNAL_SRCS = ./signal/minishell_signal.c \

RUN_SRCS = ./run/minishell_propt.c ./run/minishell_run.c ./run/minishell_fork.c \
			./run/minishell_here_doc.c ./run/minishell_fork_utils.c \
			./run/minishell_pipe.c \

PHARSING_SRCS = ./pharsing/minishell_token_init.c ./pharsing/minishell_token_data.c \
				./pharsing/minishell_token_split.c ./pharsing/minishell_variable_expansion.c \
				./pharsing/minishell_phasing_utils.c ./pharsing/minishell_remove_utils.c \

BUTILTIN_SRCS = ./builtin/minishell_builtin_check.c ./builtin/minishell_builtin_utils.c \
				./builtin/minishell_builtin.c \

SRCS =  $(FREE_SRCS) $(SIGNAL_SRCS) $(PHARSING_SRCS) $(RUN_SRCS) $(BUTILTIN_SRCS) \
		minishell.c minishell_init.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME) -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) clean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re
