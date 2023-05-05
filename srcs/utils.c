/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:01:39 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/05 16:46:15 by mpotthar         ###   ########.fr       */
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
	if (*envp == NULL)
		return (ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/ \
				local/munki:/opt/X11/bin:/Library/Apple/usr/bin", ':'));
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ':');
	return (path);
}

// build single cmd path (env path + '/' + exec)
char	*get_single_cmd_path(char **env_paths, char **cmd_split, int i)
{
	char	*path_tmp;
	char	*cmd_path;

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
	return (cmd_path);
}

// get command path
char	*get_cmd_path(char *cmd, char **envp)
{
	char	**env_paths;
	char	**cmd_split;
	char	*cmd_path;
	int		i;

	i = 0;
	env_paths = get_env_paths(envp);
	cmd_split = split_cmd(cmd);
	while (env_paths[i])
	{
		cmd_path = get_single_cmd_path(env_paths, cmd_split, i);
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

// // get command path
// char	*get_cmd_path(char *cmd, char **envp)
// {
// 	char	*path_tmp;
// 	char	**env_paths;
// 	char	**cmd_split;
// 	char	*cmd_path;
// 	int		i;

// 	i = 0;
// 	env_paths = get_env_paths(envp);
// 	cmd_split = split_cmd(cmd);
// 	while (env_paths[i])
// 	{
// 		path_tmp = ft_strjoin(env_paths[i], "/");
// 		if (!path_tmp)
// 			return (NULL);
// 		cmd_path = ft_strjoin(path_tmp, cmd_split[0]);
// 		if (!cmd_path)
// 		{
// 			free(path_tmp);
// 			return (NULL);
// 		}
// 		free(path_tmp);
// 		if (access(cmd_path, X_OK) == 0)
// 			return (cmd_path);
// 		else
// 		{
// 			free(cmd_path);
// 			cmd_path = NULL;
// 		}
// 		i++;
// 	}
// 	free_dbl_ptr(env_paths);
// 	return (NULL);
// }
