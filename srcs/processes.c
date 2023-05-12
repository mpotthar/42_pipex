/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/12 16:28:34 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ******** PROCESSES ********
// child 1 process (child_first)
void	child_1(char **argv, int *p_fd, char **envp, int *fd)
{
	close(fd[1]);
	if (fd[0] < 0)
		exit(1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		msg_error(ERR_DUP2);
	close(fd[0]);
	if (dup2(p_fd[1], STDOUT_FILENO) == -1);
		msg_error(ERR_DUP2);
	close(p_fd[0]);
	close(p_fd[1]);
	executer(argv[2], envp);
}

// child 2 process (child_last)
void	child_2(char **argv, int *p_fd, char **envp, int fd)
{
	if (fd < 0)
		exit(1);
	dup2(fd, STDOUT_FILENO);
	//error???
	close(fd);
	dup2(p_fd[0], STDIN_FILENO);
	//error???
	close(p_fd[0]);
	close(p_fd[1]);
	executer(argv[3], envp);
}
