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

EXEC = pipex.a

NAME = pipex

SRCS = pipex.c pipex_data_init.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(EXEC) : $(OBJS)
	$(MAKE) -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./
	mv libftprintf.a pipex.a
	ar rcs $(EXEC) $(OBJS)

$(NAME) : $(EXEC)
	$(CC) $(CFLAGS) $(EXEC) -o $(NAME)
	rm -f pipex.a

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
