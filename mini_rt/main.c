/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:26:53 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/23 19:19:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minirt.h"

int	main(void)
{
    int     i;
    int     j;
    int     canvas_width;
    int     canvas_height;
    t_color3 pixel;

    canvas_width = 256;
    canvas_height = 256;

    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    j = canvas_height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canvas_width)
        {
            pixel.x = (double)i / (canvas_width - 1);
            pixel.y = (double)j / (canvas_height - 1);
            pixel.z = 0.25;
            write_color(pixel);
            ++i;
        }
    --j;
    }
    return (0);
}