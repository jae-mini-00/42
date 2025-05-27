/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_lighting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:23:55 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/28 00:18:39 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	// while (lights)
	// {
	// 	if (lights->type == LIGHT_POINT)
	// 		light_color = two_vec_plus(light_color, point_light_get(scene, lights->element));
	// 	lights = lights->next;
	// }
	light_color = two_vec_plus(light_color, scene->ambient);
	return (two_vec_minus(two_vec_mult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}