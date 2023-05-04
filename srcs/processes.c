/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/04 13:03:02 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ******** PROCESSES ********
// child process
void	child(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
		msg_error(ERR_InFile);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	executer(argv[2], envp);
}

//parent process
void	parent(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd < 0)
		msg_error(ERR_OutFile);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	executer(argv[3], envp);
}