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

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "../ft_printf/libft/libft.h"

typedef struct s_cmdlist
{
	int					num;
	char				**av;
	struct s_cmdlist	*next;
}	t_cmdlist;

typedef struct s_bonusdata
{
	int			i;
	int			cmd_size;
	int			**fd;
	int			in_file;
	int			out_file;
	char		**path_split;
	pid_t		pid;
	t_cmdlist	*cmd;
}	t_bonusdata;

char		**ft_full_path(char **data);
char		**ft_path_split(char **envp);
char		*cmd_path(char *av, char **path);
void		ft_perror(char *str, int num);
void		ft_split_free(char **split_data);
void		pipex_all_free(t_bonusdata *data);
void		connect_cmd(t_cmdlist *cmd, t_cmdlist *new);
void		pipexdata_init(t_bonusdata *data, int ac, char **av, char **envp);
t_cmdlist	*make_cmd_data(char *av, char **path);
t_cmdlist	*cmd_init(t_bonusdata *cmd, int ac, char **av, char **path);

#endif
