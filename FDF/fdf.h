/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:53:57 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/13 18:54:00 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define key_esc 65307

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"
#include "./ft_printf/ft_printf.h"

typedef struct s_content
{
	void	*mlx;
	void	*win;
} t_content;

typedef struct s_map
{
	int	color;
	int	x;
	int	y;
	int	z;
} t_map;

#endif
