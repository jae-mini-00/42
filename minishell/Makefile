# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2025/03/17 21:52:51 by jaejo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

FREE_SRCS = ./free/minishell_free.c \

PHARSING_SRCS = ./pharsing/minishell_token_init.c ./pharsing/minishell_token_data.c \
				./pharsing/minishell_data_split.c \

FORK_SRCS = ./fork/minishell_fork.c \

SRCS =  $(FREE_SRCS) $(PHARSING_SRCS) $(FORK_SRCS) \
		minishell.c minishell_init.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME) -lreadline

make_bonus : $(B_OBJS)
	touch $@
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(B_OBJS) ./ft_printf/libftprintf.a -o $(NAME) -lreadline

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) clean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re
