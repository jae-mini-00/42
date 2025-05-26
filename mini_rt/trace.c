/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:38:20 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 23:21:32 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_ray	ray_init(t_vec_point3 orig, t_vec3 dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_vec_point3	ray_at(t_ray *ray, double t)
{
	t_vec_point3	at;

	at = two_vec_plus(ray->orig, vec_mult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->orig;
	ray.dir = vec_unit(two_vec_minus(two_vec_plus \
		(two_vec_plus(cam->left_bottom, vec_mult(cam->horizontal, u)), \
		vec_mult(cam->vertical, v)), cam->orig));
	return (ray);
}

t_color3	ray_color(t_ray *ray, t_sphere *sp)
{
	double	t;
	t_vec3	n;

	t = hit_sphere(sp, ray);
	if (t > 0.0)
	{
		n = vec_unit(two_vec_minus(ray_at(ray, t), sp->center));
		return (vec_mult(color3(n.x + 1, n.y + 1, n.z + 1), 0.5));
	}
	else
	{
		t = 0.5 * (ray->dir.y + 1.0);
		return (two_vec_plus(vec_mult(color3(1, 1, 1), 1.0 - t), \
		vec_mult(color3(0.5, 0.7, 1.0), t)));
	}
}
