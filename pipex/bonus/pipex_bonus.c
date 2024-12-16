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

#include "pipex_bonus.h"

void	ft_fd_close(t_bonusdata *data)
{
	int	i;

	i = 0;
	while (i < data->cmd_size - 1)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		i++;
	}
	i++;
}

void	first_work_child(t_bonusdata *data, t_cmdlist *cmd_data, char **envp)
{
	char	**av;

	data->pid = fork();
	if (data->pid == 0)
	{
		av = cmd_data->av;
		close(data->out_file);
		if (cmd_data && dup2(data->in_file, 0) == -1)
			ft_perror("Dup2_err", errno);
		if (cmd_data && dup2(data->fd[0][1], 1) == -1)
			ft_perror("Dup2_err", errno);
		ft_fd_close(data);
		close(data->in_file);
		execve(av[0], av, envp);
		pipex_all_free(data);
		ft_perror("execve_err", errno);
	}
}

void	middle_work_child(t_bonusdata *data, t_cmdlist *cmd_data, char **envp)
{
	char	**av;

	data->pid = fork();
	if (data->pid == 0)
	{
		av = cmd_data->av;
		close(data->out_file);
		close(data->in_file);
		if (cmd_data && dup2(data->fd[cmd_data->num - 2][0], 0) == -1)
			ft_perror("Dup2_err", errno);
		if (cmd_data && dup2(data->fd[cmd_data->num - 1][1], 1) == -1)
			ft_perror("Dup2_err", errno);
		ft_fd_close(data);
		execve(av[0], av, envp);
		pipex_all_free(data);
		ft_perror("execve_err", errno);
	}
}

void	last_work_child(t_bonusdata *data, t_cmdlist *cmd_data, char **envp)
{
	char	**av;

	data->pid = fork();
	if (data->pid == 0)
	{
		av = cmd_data->av;
		close(data->in_file);
		if (cmd_data && dup2(data->fd[cmd_data->num - 2][0], 0) == -1)
			ft_perror("Dup2_err", errno);
		if (cmd_data && dup2(data->out_file, 1) == -1)
			ft_perror("Dup2_err", errno);
		ft_fd_close(data);
		close(data->out_file);
		execve(av[0], av, envp);
		pipex_all_free(data);
		ft_perror("execve_err", errno);
	}
}

void	make_pipe(t_bonusdata *data)
{
	int	i;

	i = 0;
	data->fd = (int **)malloc (sizeof(int *) * data->cmd_size - 1);
	if (!data->fd)
		ft_perror("fd_malloc", errno);
	while (i < data->cmd_size - 1)
	{
		data->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!data->fd[i])
			ft_perror("fd_malloc", errno);
		if (pipe(data->fd[i]) == -1)
			ft_perror("pipe", errno);
		i++;
	}
}

int	main	(int ac, char **av, char **envp)
{
	t_bonusdata	data;
	t_cmdlist			*now;

	if (ac < 5)
		ft_perror("Insufficient argument value", 1);
	pipexdata_init(&data, ac, av, envp);
	make_pipe(&data);
	now = data.cmd->next;
	first_work_child(&data, data.cmd, envp);
	while (data.i++ < data.cmd_size)
	{
		middle_work_child(&data, now, envp);
		now = now->next;
		close(data.fd[now->num - 2][1]);
	}
	last_work_child(&data, now, envp);
	ft_fd_close(&data);
	waitpid(data.pid, NULL, 0);
	close(data.in_file);
	close(data.out_file);
	pipex_all_free(&data);
}
