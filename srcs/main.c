#include "pipex.h"

// free double pointer
char **free_dbl_ptr(char **ptr)
{
	int i;

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
char **all_paths(char **envp)
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
char **split_cmd(char *cmd)
{
	char **cmd_split;

	cmd_split = ft_split(cmd, ' ');
	return (cmd_split);
}

// get path of cmd
char *path_cmd(char **envp, char *cmd)
{
	char	**paths;
	char	**cmd_split;
	char 	*path_tmp;
	char	*path_cmd;
	int		i;

	i = 0;
	paths = all_paths(envp);
	cmd_split = split_cmd(cmd);
	while (paths[i])
	{
		path_tmp = ft_strjoin(paths[i], "/");
		if (!path_tmp)
			return (NULL);
		path_cmd = ft_strjoin(path_tmp, cmd_split[0]);
		if (!path_cmd)
		{
			free(path_tmp);
			return (NULL);
		}
		free(path_tmp);
		if (access(path_cmd, F_OK) == 0)
		{
			ft_printf(GREEN"found path\n"ESC);
			break ;
		}
		else
			free(path_cmd);
		i++;
	}
	free_dbl_ptr(cmd_split);
	free_dbl_ptr(paths);
	return (path_cmd);
}





// ******** MAIN ********
int	main(int argc, char **argv, char **envp)
{
	// if (argc != 5)
	// 	return (1);
	char *path = path_cmd(envp, argv[1]);
	ft_printf(RED"PATH: %s\n"ESC, path);
	free(path);
}

