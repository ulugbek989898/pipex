/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:47:58 by uisroilo          #+#    #+#             */
/*   Updated: 2022/07/26 13:20:22 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	child1_process(char **argv, t_pipex *pipex, char **envp)
{
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile == -1)
		ft_putstr(argv[1], strerror(errno));
	pipex->str_path = ft_path_cmd(envp);
	pipex->str_split = ft_split(pipex->str_path, ':');
	pipex->get_1cmd = ft_split(argv[2], ' ');
	pipex->real_path1 = get_path_access(pipex->str_split, pipex->get_1cmd[0]);
	if (!pipex->real_path1)
	{
		free_split(pipex->get_1cmd);
		free_split(pipex->str_split);
		exit(127);
	}
	if (dup2(pipex->fd_infile, STDIN_FILENO) == -1)
		(strerror(errno));
	close(pipex->fd_infile);
	if (dup2(pipex->fd[1], STDOUT_FILENO) == -1)
		(strerror(errno));
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (execve(pipex->real_path1, ft_split(argv[2], ' '), envp) == -1)
		(strerror(errno));
	exit (1);
}

void	parent_process(char **argv, t_pipex *pipex, char **envp)
{
	pipex->fd_outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->fd_outfile == -1)
		exit(1);
	pipex->str_path = ft_path_cmd(envp);
	pipex->str_split = ft_split(pipex->str_path, ':');
	pipex->get_2cmd = ft_split(argv[3], ' ');
	pipex->real_path2 = get_path_access(pipex->str_split, pipex->get_2cmd[0]);
	if (!pipex->real_path2)
	{
		free_split(pipex->get_2cmd);
		free_split(pipex->str_split);
		exit(127);
	}
	if (dup2(pipex->fd_outfile, STDOUT_FILENO) == -1)
		(strerror(errno));
	if (dup2(pipex->fd[0], STDIN_FILENO) == -1)
		(strerror(errno));
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	close(pipex->fd_outfile);
	if (execve(pipex->real_path2, ft_split(argv[3], ' '), envp) == -1)
		(strerror(errno));
	exit (127);
}

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		if (pipe(pipex.fd) == -1)
			(strerror(errno));
		pipex.pid1 = fork();
		if (pipex.pid1 == -1)
			(strerror(errno));
		if (pipex.pid1 == 0)
			child1_process(argv, &pipex, envp);
		else
		{
			parent_process(argv, &pipex, envp);
			waitpid(pipex.pid1, NULL, 0);
			// close(pipex.fd[0]);
			// close(pipex.fd[1]);
		}
	}
	else
	{
		write(1, "Wrong argument count!\n", 23);
		return (1);
	}
}
