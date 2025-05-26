/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:47:08 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 22:00:08 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define FALSE 0
# define TRUE 1

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_vec_point3;
typedef struct s_vec3	t_color3;

struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_ray
{
	t_vec_point3	orig;
	t_vec3			dir;
}	t_ray;

typedef struct s_camera
{
	t_vec_point3	orig;
	double			viewport_h;
	double			viewport_w;
	t_vec3			horizontal;
	t_vec3			vertical;
	double			focal_len;
	t_vec_point3	left_bottom;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_sphere
{
	t_vec_point3	center;
	double			radius;
	double			radius2;
}	t_sphere;

#endif