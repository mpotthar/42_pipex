/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:47 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/09 12:04:50 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipe(int p_fd[2])
{
	close(p_fd[0]);
	close(p_fd[1]);
}

static int	wait_pids(int p_fd[2], pid_t pid_1, pid_t pid_2)
{
	int		status;
	int		exit_status;

	exit_status = 1;
	close_pipe(p_fd);
	waitpid(pid_1, NULL, 0);
	if (waitpid(pid_2, &status, 0) == -1)
		msg_error("waitpid: ");
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

static void	open_fds(int *fd, char **argv)
{
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] < 0)
		perror(ERR_OUTFILE);
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		perror(ERR_INFILE);
}

// ******** MAIN ********
int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd[2];
	int		exit_status;

	if (argc != 5)
		msg_error(ERR_ARGC);
	open_fds(fd, argv);
	if (pipe(p_fd) == -1)
		return (msg_stderr(ERR_PIPE));
	pid_1 = fork();
	if (pid_1 == -1)
		return (msg_stderr(ERR_FORK));
	if (pid_1 == 0)
		child_1(argv, p_fd, envp, fd);
	close(fd[0]);
	pid_2 = fork();
	if (pid_2 == -1)
		return (msg_stderr(ERR_FORK));
	if (pid_2 == 0)
		child_2(argv, p_fd, envp, fd[1]);
	exit_status = wait_pids(p_fd, pid_1, pid_2);
	close(fd[1]);
	exit(exit_status);
}
