/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:07:19 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/12 17:47:53 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	msg_stderr(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_error(char *err)
{
	perror(err);
	exit (EXIT_FAILURE);
}

bool	ft_error_ret_true(char *err)
{
	perror(err);
	return (true);
}

int	msg_fork_error(int *fd, int *p_fd)
{
	ft_putendl_fd("pipex: fork error", STDERR_FILENO);
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	if (p_fd[0] >= 0)
		close(p_fd[0]);
	if (p_fd[1] >= 0)
		close(p_fd[1]);
	return (1);
}
