/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:47 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/12 17:47:35 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// close pipe file descriptors
static void	close_pipe(int p_fd[2])
{
	close(p_fd[0]);
	close(p_fd[1]);
}

static void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

// wait for child processes to finish, then return exit status
static int	wait_pids(int p_fd[2], pid_t pid_1, pid_t pid_2, int fd[2])
{
	int		status;
	int		exit_status;

	exit_status = 1;
	close_pipe(p_fd);
	close_fds(fd);
	waitpid(pid_1, NULL, 0);
	if (waitpid(pid_2, &status, 0) == -1)
		msg_error("waitpid: ");
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	return (exit_status);
}

// open file descriptors for infile and outfile
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
	if (pipe(p_fd) == -1)
		return (msg_stderr(ERR_PIPE));
	open_fds(fd, argv);
	pid_1 = fork();
	if (pid_1 == -1)
		return (msg_fork_error(fd, p_fd));
	if (pid_1 == 0)
		child_1(argv, p_fd, envp, fd);
	pid_2 = fork();
	if (pid_2 == -1)
		return (msg_fork_error(fd, p_fd));
	if (pid_2 == 0)
		child_2(argv, p_fd, envp, fd);
	exit_status = wait_pids(p_fd, pid_1, pid_2, fd);
	exit(exit_status);
}
