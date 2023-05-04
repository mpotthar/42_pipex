/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:49 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/04 13:41:20 by mpotthar         ###   ########.fr       */
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
		msg_error(ERR_CMDPATH);
		exit(1);
	}
	cmd_split = split_cmd(command);
	execve(cmd_path, cmd_split, envp);
	msg_error(ERR_EXECVE);
}
