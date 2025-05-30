/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/30 21:10:19 by jaejo            ###   ########.fr       */
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

// int	main(void)
// {
//     int     i;
//     int     j;

//     double u;
//     double v;

//     t_color3 pixel_color;
//     t_camera cam;
//     t_canvas canv;
//     t_ray ray;
//     t_object *world;

//     canv = canvas(400, 300);
//     cam = camera(&canv, vec_point3(0, 0, 0));
//     world = object_init(SP, sphere_init(vec_point3(-2, 0, -5), 2), color3(0.5, 0, 0));
//     object_add(&world, object_init(SP, sphere_init(vec_point3(2, 0, -5), 2), color3(0, 0.5, 0)));
//     object_add(&world, object_init(SP, sphere_init(vec_point3(0, -1000, 0), 990), color3(1, 1, 1)));
//     printf("P3\n%d %d\n255\n", canv.width, canv.height);
//     j = canv.height - 1;
//     while (j >= 0)
//     {
//         i = 0;
//         while (i < canv.width)
//         {
//             u = (double)i / (canv.width - 1);
//             v = (double)j / (canv.height - 1);
//             ray = ray_primary(&cam, u, v);
//             pixel_color = ray_color(&ray, world);
//             write_color(pixel_color);
//             ++i;
//         }
//     --j;
//     }
//     return (0);
// }