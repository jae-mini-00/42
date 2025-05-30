/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:00:23 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/30 21:06:38 by jaejo            ###   ########.fr       */
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

t_scene	*scene_init(int	fd)
{
	t_scene		*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(1960, 1080);
	scene->camera = camera(&scene->canvas, vec_point3(0, 0, 1));
	// world = object_init(SP, sphere_init(vec_point3(-2, 0, -5), 2), color3(0.5, 0, 0));
    // object_add(&world, object_init(SP, sphere_init(vec_point3(2, 0, -5), 2), color3(0, 0.5, 0)));
    // object_add(&world, object_init(SP, sphere_init(vec_point3(0, -1000, 0), 950), color3(1, 1, 1)));
	// scene->world = world;
	lights = object_init(LIGHT_POINT, light_point(vec_point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1;
	scene->ambient = vec_mult(color3(1, 1, 1), ka);
	return (scene);
}
