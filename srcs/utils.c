/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:39 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/04 13:21:31 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// free double pointer
char	**free_dbl_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

// get all paths from envp and split by ':'
static char	**get_env_paths(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

// split cmd by ' '
char	**split_cmd(char *cmd)
{
	char	**cmd_split;

	cmd_split = ft_split(cmd, ' ');
	return (cmd_split);
}

// get command path
char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_tmp;
	char	**env_paths;
	char	**cmd_split;
	char	*cmd_path;
	int		i;

	i = 0;
	env_paths = get_env_paths(envp);
	cmd_split = split_cmd(cmd);
	while (env_paths[i])
	{
		path_tmp = ft_strjoin(env_paths[i], "/");
		if (!path_tmp)
			return (NULL);
		cmd_path = ft_strjoin(path_tmp, cmd_split[0]);
		if (!cmd_path)
		{
			free(path_tmp);
			return (NULL);
		}
		free(path_tmp);
		if (access(cmd_path, X_OK) == 0)
			return (cmd_path);
		else
		{
			free(cmd_path);
			cmd_path = NULL;
		}
		i++;
	}
	free_dbl_ptr(env_paths);
	return (NULL);
}
