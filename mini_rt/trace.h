/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:36:51 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 23:21:45 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "./types.h"
# include "./vec_utils.h"

t_ray			ray_init(t_vec_point3 orig, t_vec3 dir);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3		ray_color(t_ray *r, t_sphere *sp);
t_vec_point3	ray_at(t_ray *ray, double t);
double			hit_sphere(t_sphere *sp, t_ray *ray);

#endif