/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:47 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/08 11:33:43 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipe(int p_fd[2])
{
	close(p_fd[0]);
	close(p_fd[1]);
}

static void	waiting(int p_fd[2], pid_t pid_1, pid_t pid_2)
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
	exit(exit_status);
}

// ******** MAIN ********
int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (argc != 5)
		msg_error(ERR_ARGC);
	if (pipe(p_fd) == -1)
		return (msg_stderr(ERR_PIPE));
	pid_1 = fork();
	if (pid_1 == -1)
		return (msg_stderr(ERR_FORK));
	if (pid_1 == 0)
		child_1(argv, p_fd, envp);
	pid_2 = fork();
	if (pid_2 == -1)
		return (msg_stderr(ERR_FORK));
	if (pid_2 == 0)
		child_2(argv, p_fd, envp);
	waiting(p_fd, pid_1, pid_2);
}
