/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:58:13 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 22:01:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "./types.h"
# include "./vec_utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_vec_point3 origin);
t_sphere	sphere(t_vec_point3 center, double radius);

#endif