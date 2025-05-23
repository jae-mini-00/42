/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo < jaejo@student.42gyeongsan.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:50:50 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/23 19:13:52 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./print.h"

void	write_color(t_color3 pixel_color)
{
	printf("%d %d %d\n", (int)(255.999 * pixel_color.x), \
						(int)(255.999 * pixel_color.y), \
						(int)(255.999 * pixel_color.z));
}
