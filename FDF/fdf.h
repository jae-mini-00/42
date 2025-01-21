/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:57 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/13 18:54:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define KEY_ESC 65307

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_content
{
	int		bpp;
	int		color;
	int		endian;
	int		width;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_addr;
}	t_content;

typedef struct s_pos
{
	float			x;
	float			y;
	float			z;
	struct s_pos	*new;
	struct s_pos	*next;
}	t_pos;

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		x_offset;
	int		y_offset;
	int		scale;
	t_pos	*p_data;
}	t_map;

int		x_hook(t_content *c_data);
int		key_hook(int keycode, t_content *c_data);
int		create_trgb(int t, int r, int g, int b);
void	pos_free(t_pos *data);
void	ft_split_free(char **data);
void	ft_perror(char *err, int num);
void	make_image(t_content *c_data, t_map *m_data);
void	fdf_file_check(char *file, int ac, t_map *m_data);
void	fdf_init(t_content *c_data, t_map *m_data, char *file);
void	my_mlx_pixel_put(t_content *data, int x, int y, int color);
//void	make_image_line(t_pos *data, t_pos *next_data, t_content *c_data, t_map *m_data);
void	make_line(t_pos *data, float d_x, float d_y, float step, t_content *c_data);
void	make_image_line(t_pos *data, t_pos *next_data, t_content *c_data);
//void	make_line(t_pos *data, t_content *c_data, t_map *m_data);
t_pos	*fdf_pos_init(t_pos *data, int fd, int x, int y);
t_pos	*next_height_pos(t_pos *data, int pass);
t_pos	*fdf_pos_init(t_pos *data, int fd, int x, int y);

#endif
