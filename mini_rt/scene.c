/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:00:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 22:02:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./scene.h"

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	camera(t_canvas *canvas, t_vec_point3 orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = two_vec_minus(two_vec_minus(two_vec_minus(cam.orig, \
		vec_div(cam.horizontal, 2)), vec_div(cam.vertical, 2)), \
		vec3(0, 0, focal_len));
	return (cam);
}

t_sphere	sphere(t_vec_point3 center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}
