#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

typedef struct s_data 
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_paths;
	char	**cmd_split;
	char	*cmd_path;
}	t_data;

#endif