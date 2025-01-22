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
# define KEY_PLUS 65451
# define KEY_MINUS 65453
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_ONE 49

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_pos
{
	int				color;
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
	char	*file;
	float	d_x;
	float	d_y;
	float	step;
	float	abs_dx;
	float	abs_dy;
	float	xinc;
	float	yinc;
  t_map m_data;
}	t_content;

int		x_hook(t_content *c_data);
int		key_hook(int keycode, t_content *c_data);
int		create_trgb(int t, int r, int g, int b);
void	pos_free(t_pos *data);
void	ft_split_free(char **data);
void	ft_perror(char *err, int num);
void	make_line(t_pos *data, t_content *c_data);
void	make_image(t_content *c_data, t_map *m_data);
void	fdf_file_check(char *file, int ac, t_map *m_data);
void	fdf_init(t_content *c_data, t_map *m_data, char *file);
void	my_mlx_pixel_put(t_content *data, int x, int y, int color);
void	make_image_line(t_pos *data, t_pos *next_data, t_content *c_data);
t_pos	*fdf_pos_init(t_pos *data, int fd, int x, int y);
t_pos	*next_height_pos(t_pos *data, int pass);
t_pos	*fdf_pos_init(t_pos *data, int fd, int x, int y);
void	fdf_init_bonuse(t_content *c_data, t_map *m_data, char *file, int scale);
void	fdf_init_left(t_content *c_data, t_map *m_data, char *file, int scale);
void	fdf_init_right(t_content *c_data, t_map *m_data, char *file, int scale);
void	fdf_init_up(t_content *c_data, t_map *m_data, char *file, int scale);
void	fdf_init_down(t_content *c_data, t_map *m_data, char *file, int scale);
void	fdf_plus(t_content *c_data);
void	fdf_minus(t_content *c_data);
void	fdf_left(t_content *c_data);
void	fdf_right(t_content *c_data);
void	fdf_up(t_content *c_data);
void	fdf_down(t_content *c_data);
void	fdf_different_make(t_content *c_data, t_map *m_data, float sin, float cos);
void	fdf_different_one(t_content *c_data);
void	make_pixel(t_content *c_data, t_map *m_data);
void	make_width_line(t_content *c_data, t_map *m_data);
void	make_height_line(t_content *c_data, t_map *m_data);

#endif
