/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:49 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/12 16:56:41 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ******** EXECUTER ********
void	executer(char *command, char **envp)
{
	char	**cmd_split;
	char	*cmd_path;

	cmd_path = NULL;
	cmd_split = ft_get_cmd_line_elements(command);
	if (cmd_split)
		cmd_path = get_cmd_path(cmd_split[0], envp);
	if (!cmd_path)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		ft_putstr_fd(command, STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		if (cmd_split)
			free_dbl_ptr(cmd_split);
		exit(127);
	}
	if (execve(cmd_path, cmd_split, envp) == -1)
	{
		free(cmd_path);
		free_dbl_ptr(cmd_split);
		msg_error(ERR_EXECVE);
	}
}
