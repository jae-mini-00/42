/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:42:40 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/06 14:42:42 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pipex.h"

void	ft_split_free(char **split_data)
{
	int	i;

	i = 0;
	while (split_data[i])
	{
		free(split_data[i]);
		i++;
	}
	free(split_data);
}

int	main(int ac, char **av, char **envp)
{
	t_pipexdata	data;
 
	//if (ac < 5)
	//	return (0);
	pipexdata_init(&data, ac, av, envp);
	ft_split_free(data.path_split);
	t_cmdlist *temp;
	t_cmdlist *now = data.cmd;
	while (now)
	{
		temp = now->next;
		ft_split_free(now->av);
		free(now);
		now = temp;
	}
	return (0);
}
