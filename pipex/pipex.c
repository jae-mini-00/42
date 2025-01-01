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

#include "pipex.h"

void	first_work_child(t_pipexdata *data, t_cmdlist *cmd_data, char **envp)
{
	char	**av;

	av = cmd_data->av;
	close(data->out_file);
	close(data->fd[0]);
	if (cmd_data && dup2(data->in_file, 0) == -1)
		ft_perror("Dup2_err", errno);
	if (cmd_data && dup2(data->fd[1], 1) == -1)
		ft_perror("Dup2_err", errno);
	close(data->fd[1]);
	close(data->in_file);
	execve(av[0], av, envp);
	pipex_all_free(data);
	ft_perror("execve_err", errno);
}

void	last_work_child(t_pipexdata *data, t_cmdlist *cmd_data, char **envp)
{
	char	**av;

	av = cmd_data->av;
	close(data->fd[1]);
	close(data->in_file);
	if (cmd_data && dup2(data->fd[0], 0) == -1)
		ft_perror("Dup2_err", errno);
	if (cmd_data && dup2(data->out_file, 1) == -1)
		ft_perror("Dup2_err", errno);
	close(data->fd[0]);
	close(data->out_file);
	execve(av[0], av, envp);
	pipex_all_free(data);
	ft_perror("execve_err", errno);
}

int	main(int ac, char **av, char **envp)
{
	t_pipexdata	data;

	if (ac < 5)
		ft_perror("Insufficient argument value", 1);
	pipexdata_init(&data, ac, av, envp);
	if (pipe(data.fd) == -1)
		ft_perror("pipe", errno);
	data.pid = fork();
	if (data.pid == 0)
		first_work_child(&data, data.cmd, envp);
	data.pid = fork();
	if (data.pid == 0)
		last_work_child(&data, data.cmd->next, envp);
	close(data.fd[0]);
	close(data.fd[1]);
	waitpid(data.pid, NULL, 0);
	close(data.in_file);
	close(data.out_file);
	pipex_all_free(&data);
	return (0);
}
	/*cmd_data = data.cmd->next;
	while(i < ac - 1)
	{
		data->pid = fork(data->pid);
		if (data.pid == 0);
			work_child(data, cmd_data);
		cmd_data = cmd_data->next;
		i++;
	}*/
