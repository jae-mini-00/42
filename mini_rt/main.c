/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/26 22:05:05 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

int	main(void)
{
    int     i;
    int     j;

    double u;
    double v;

    t_color3 pixel_color;
    t_camera cam;
    t_canvas canv;
    t_ray ray;
    t_sphere sp;

    sp = sphere(vec_point3(0, 0, -5), 2);
    canv = canvas(400, 300);
    cam = camera(&canv, vec_point3(0, 0, 0));
    printf("P3\n%d %d\n255\n", canv.width, canv.height);
    j = canv.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canv.width)
        {
            u = (double)i / (canv.width - 1);
            v = (double)j / (canv.height - 1);
            ray = ray_primary(&cam, u, v);
            pixel_color = ray_color(&ray, &sp);
            write_color(pixel_color);
            ++i;
        }
    --j;
    }
    return (0);
}