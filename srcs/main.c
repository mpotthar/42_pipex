/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:47 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/04 13:06:16 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ******** MAIN ******** 
int	main(int argc, char **argv, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		return (msg_stderr(ERR_ARGC));
	if (pipe(p_fd) == -1)
		return (msg_stderr(ERR_PIPE));
	pid = fork();
	if (pid == -1)
		return (msg_stderr(ERR_FORK));
	if (pid == 0)
		child(argv, p_fd, envp);
	parent(argv, p_fd, envp);
}
