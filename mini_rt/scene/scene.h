/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:58:13 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/29 16:56:42 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../types.h"
# include "../vec/vec_utils.h"

void        object_add(t_object **list, t_object *new);
t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_vec_point3 origin);
t_sphere	*sphere_init(t_vec_point3 center, double radius);
t_object    *object_last(t_object *list);
t_object	*object_init(t_object_type type, void *element, t_color3 albedo);
t_light     *light_point(t_vec_point3 light_origin, t_color3 light_color, double bright_ratio);
t_scene     *scene_init(void);

#endif