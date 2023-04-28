#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

// colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define ESC "\033[0m"

// error
# define ERR_ARGC "Error: wrong number of arguments\n"

typedef struct s_data 
{
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_paths;
	char	**cmd_split;
	char	*cmd_path;

	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		fd_in;
	int		fd_out;
}	t_data;

// functions

// main.c

// error.c
int		msg_stderr(char *err);
void	msg_error(char *err);

#endif