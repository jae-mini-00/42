/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:57:26 by jaejo             #+#    #+#             */
/*   Updated: 2024/12/06 14:57:28 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./ft_printf/libft/libft.h"

typedef struct s_cmdlist
{
	int					num;
	char				**av;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_pipexdata
{
	int			i;
	int			in_file;
	int			out_file;
	t_cmdlist	*cmd;
	char		**path_split;
}	t_pipexdata;

char	**ft_path_split(char **envp);
char	**ft_full_path(char **data);
void	pipexdata_init(t_pipexdata *data, int ac, char **av, char **envp);

#endif
