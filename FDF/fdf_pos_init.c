/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:16:39 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/17 23:16:41 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	*pos_create(int i, int j, char *data)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		return (0);
	new->x = i;
	new->y = j;
	new->z = ft_atoi(data);
    new->new = NULL;
    new->next = NULL;
	return (new);
}

void    pos_add_back(t_pos *data, t_pos *back)
{
    t_pos *now;

    now = data;
    while (now->next)
        now = now->next;
    now->next = back;
}

void    fdf_pos_init(t_pos *data, int fd)
{
    char *str;
    char **s_data;
    int i;
    int j;

    str = get_next_line(fd);
    s_data = ft_split(str, ' ');
    *data = pos_create(0, 0, s_data[0]);
    i = 1;
    j = 0;
    while (1)
    {
        while(s_data[i])
        {
            data->new = pos_create(i, j , s_data[i]);
            pos_add_back(data, new);
            i++;
        }
        ft_split_free(s_data);
        i = 0;
        j++;
        str = get_next_line(fd);
        if (!str)
            return ;
        s_data = ft_split(str, ' ');
    }
}