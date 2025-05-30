/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:47:08 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/30 21:46:35 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define FALSE 0
# define TRUE 1
# define SP 0
# define LIGHT_POINT 1
# define EPSILON 1e-6 // 0.000001
# define LUMEN 3

# include "./ft_printf/ft_printf.h"
# include "./free/free.h"

typedef int				t_bool;
typedef int				t_object_type;
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
	t_vec3			cam_dir;
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

typedef struct s_hit_record
{
	t_vec_point3	p;
	t_vec3			normal;
	double			tmin;
	double			tmax;
	double			t;
	t_bool			front_face;
	t_color3		albedo;
}	t_hit_record;

typedef struct	s_object
{
    t_object_type	type;
    void			*element;
	t_color3		albedo;
    void			*next;
}	t_object;

typedef struct	s_light
{
    t_vec_point3	origin;
    t_color3		light_color;
    double			bright_ratio;
}	t_light;

typedef struct	s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

#endif