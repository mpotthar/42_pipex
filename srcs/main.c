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
char **get_env_paths(char **envp)
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
int path_cmd(t_data *pipex, char *cmd)
{
	char 	*path_tmp;
	int		i;

	i = 0;
	pipex->env_paths = get_env_paths(pipex->envp);
	pipex->cmd_split = split_cmd(cmd);
	while (pipex->env_paths[i])
	{
		path_tmp = ft_strjoin(pipex->env_paths[i], "/");
		if (!path_tmp)
			return (0);
		pipex->cmd_path = ft_strjoin(path_tmp, pipex->cmd_split[0]);
		if (!(pipex->cmd_path))
		{
			free(path_tmp);
			return (0);
		}
		free(path_tmp);
		if (access(pipex->cmd_path, X_OK) == 0)
			return (1);
		else
		{
			free(pipex->cmd_path);
			pipex->cmd_path = NULL;
		}
		i++;
	}
	free_dbl_ptr(pipex->env_paths);
	return (3);
}





// ******** MAIN ******** 
int	main(int argc, char **argv, char **envp)
{
	t_data *pipex;

	if (argc != 5)
		return (msg_stderr(ERR_ARGC));
	pipex = (t_data*)malloc(sizeof(t_data));
	if (!pipex)
		return (1);
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		msg_error(ERR_InFile);
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
		msg_error(ERR_OutFile);

	int result = path_cmd(pipex, argv[2]);
	ft_printf(RED"RESULT:	%i\nPATH:	%s\n"ESC, result, pipex->cmd_path);
	
	
	execve(pipex->cmd_path, pipex->cmd_split, pipex->envp);
	
	
	if (pipex->cmd_path)
		free(pipex->cmd_path);
	if (pipex->cmd_split)
		free_dbl_ptr(pipex->cmd_split);
	free(pipex);
}

