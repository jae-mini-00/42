/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/31 15:23:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     main(int ac, char **av)
{
    // int         i;
    // int         j;
    // double      u;
    // double      v;
    // t_color3    pixel_color;
    t_scene     *scene;

    scene = NULL;
    file_init(scene, ac, av[1]);
    (void)scene;
    //scene = scene_init();
    // printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    // j = scene->canvas.height - 1;
    // while (j >= 0)
    // {
    //     i = 0;
    //     while (i < scene->canvas.width)
    //     {
    //         u = (double)i / (scene->canvas.width - 1);
    //         v = (double)j / (scene->canvas.height - 1);
    //         scene->ray = ray_primary(&scene->camera, u, v);
    //         pixel_color = ray_color(scene);
    //         write_color(pixel_color);
    //         ++i;
    //     }
    //     --j;
    // }
    // return (0);
}
