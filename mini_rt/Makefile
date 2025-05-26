# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2025/05/26 23:00:24 by jaejo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = minirt

PRINT_SRCS = ./write_color.c \

TRACE_SRCS = ./trace.c ./hit_sphere.c \

SCENE_SRCS = ./scene.c \

VEC_UTILS_SRCS = ./make_vec_utils.c ./vec_minus_utils.c ./vec_mult_div_utils.c \
				 ./vec_operator_utils.c ./vec_plus_utils.c \

SRCS = ./main.c $(PRINT_SRCS) $(VEC_UTILS_SRCS) $(TRACE_SRCS) $(SCENE_SRCS)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf 
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

make_bonus : $(B_OBJS)
	touch $@
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

bonus : make_bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	rm -f make_bonus
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re bonus
