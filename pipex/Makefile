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

NAME = pipex

SRCS = pipex.c pipex_data_init.c pipex_cmd_init.c pipex_free_and_err.c \

B_SRCS = pipex_bonus.c pipex_data_init_bonus.c pipex_cmd_init_bonus.c \
         pipex_free_and_err_bonus.c \

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -o $(NAME)

make_bonus : $(B_OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(B_OBJS) -L./ft_printf -lftprintf -o $(NAME)
	touch $@
	rm make_bonus

bonus : make_bonus

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
