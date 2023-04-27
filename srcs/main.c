#include "pipex.h"

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

int	main(int argc, char **argv, char **envp)
{
	// if (argc != 5)
	// 	return (1);
	char **env_path = all_env_path(envp);
	ft_printf("%s", env_path[0]);
}

