/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_n_err.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:32:49 by jaejo             #+#    #+#             */
/*   Updated: 2025/01/16 16:32:51 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_perror(char *err, int num)
{
	errno = num;
	perror(err);
	exit(num);
}

void	ft_split_free(char **data)
{
	int	i;

	i = 0;
	while(data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}
/*
void	file_check(char *file, int ac)
{
	char **file_name;
	int		i;

	i = 0;
	if (ac != 2)
		ft_perror ("Invalid number of arguments", 22);
	file_name = ft_split(file, '.');
	if (!file_name)
		ft_perror("split error", errno);
	while (file_name[i])
		i++;
	if (ft_strncmp(file_name[i - 1], "fdf", 4) == 0)
	{
		ft_split_free(file_name);
		return ;
	}
	ft_split_free(file_name);
	ft_perror("Not .fdf", 9);
}*/
