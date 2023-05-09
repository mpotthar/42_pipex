/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:49 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/09 15:02:20 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ******** EXECUTER ********
void	executer(char *command, char **envp)
{
	char	*cmd_path;
	char	**cmd_split;

	cmd_path = get_cmd_path(command, envp);
	if (!cmd_path)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit(127);
	}
	cmd_split = split_cmd(command);
	//error
	//free path
	if (execve(cmd_path, cmd_split, envp) == -1)
		msg_error(ERR_EXECVE);
}
