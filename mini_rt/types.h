/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:47:08 by jaejo             #+#    #+#             */
/*   Updated: 2025/05/20 21:28:39 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_vec_point3;
typedef struct s_vec3 t_color3;

struct s_vec3
{
    double x;
    double y;
    double z;
};

#endif