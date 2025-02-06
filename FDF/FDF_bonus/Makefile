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

SRCS =  fdf_bonus.c fdf_hook_bonus.c  fdf_free_n_err_bonus.c fdf_file_check_bonus.c \
				fdf_utils_bonus.c fdf_init_bonus.c  fdf_pos_init_bonus.c fdf_make_line_bonus.c \
				fdf_make_image_bonus.c fdf_p_m_bonus.c fdf_init2_bonus.c fdf_map_move_bonus.c \
				fdf_make_different_bonus.c  fdf_rotation_bonus.c  fdf_colorfull_bonus.c \

B_SRCS =  \

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf 
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

make_bonus : $(B_OBJS)
	touch $@
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./minilib-linux
	$(CC) $(CFLAGS) $(B_OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lm -lX11 -o $(NAME)

bonus : make_bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	rm -f make_bonus
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re bonus
