/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/15 12:36:45 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_all_fds(int *fd, int *p_fd)
{
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (p_fd[0] != -1)
		close(p_fd[0]);
	if (p_fd[1] != -1)
		close(p_fd[1]);
}

// ******** PROCESSES ********
// child 1 process (child_first)
void	child_1(char **argv, int *p_fd, char **envp, int *fd)
{
	bool	error;

	error = false;
	if (fd[1] != -1)
		close(fd[1]);
	if (fd[0] < 0)
	{
		close_all_fds(fd, p_fd);
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error = ft_error_ret_true(ERR_DUP2);
	if (fd[0] != -1)
		close(fd[0]);
	if (error == false && dup2(p_fd[1], STDOUT_FILENO) == -1)
		error = ft_error_ret_true(ERR_DUP2);
	close(p_fd[0]);
	close(p_fd[1]);
	if (error == false)
		executer(argv[2], envp);
	exit(1);
}

// child 2 process (child_last)
void	child_2(char **argv, int *p_fd, char **envp, int *fd)
{
	bool	error;

	error = false;
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] < 0)
	{
		close_all_fds(fd, p_fd);
		exit(1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error = ft_error_ret_true(ERR_DUP2);
	if (fd[1] != -1)
		close(fd[1]);
	if (dup2(p_fd[0], STDIN_FILENO) == -1)
		error = ft_error_ret_true(ERR_DUP2);
	close(p_fd[0]);
	close(p_fd[1]);
	if (error == false)
		executer(argv[3], envp);
	exit(1);
}
