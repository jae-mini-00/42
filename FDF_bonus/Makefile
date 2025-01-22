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

NAME = fdf

SRCS =  fdf.c fdf_hook.c  fdf_free_n_err.c fdf_file_check.c  fdf_utils.c \
				fdf_init.c  fdf_pos_init.c fdf_make_line.c  fdf_make_image.c fdf_p_m_bonus.c \

B_SRCS =  \

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf 
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -o $(NAME)

make_bonus : $(B_OBJS)
	touch $@
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./minilib-linux
	$(CC) $(CFLAGS) $(B_OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -o $(NAME)

bonus : make_bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	rm -f make_bonus
	$(MAKE) clean -C ./ft_printf
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re bonus
