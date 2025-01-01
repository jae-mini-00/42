# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2024/10/29 14:44:00 by jaejo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

EXEC = pushswap.a

NAME = push_swap

SRCS = pivot_opperation.c push_opperation0.c push_opperation1.c push_opperation2.c \
       push_swap.c push_swap_algorithm.c push_swap_cost.c push_swap_error_check.c \
       push_swap_greedy.c push_swap_make_data.c push_swap_pivot_setting.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(EXEC) : $(OBJS)
	$(MAKE) -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./
	mv libftprintf.a pushswap.a
	ar rcs $(EXEC) $(OBJS)

$(NAME) : $(EXEC)
	$(CC) $(CFLAGS) $(EXEC) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re bonus
