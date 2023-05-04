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
# define ERR_InFile "Error: can't open input file"
# define ERR_OutFile "Error: can't open or create output file"
# define ERR_Pipe "Error: pipe failed\n"
# define ERR_Fork "Error: fork failed\n"
# define ERR_CmdPath "Error: command not found\n"
# define ERR_Execve "Error: execve failed\n"

// functions

// main.c

// error.c
int		msg_stderr(char *err);
void	msg_error(char *err);

// processes.c
void	child(char **argv, int *p_fd, char **envp);
void	parent(char **argv, int *p_fd, char **envp);

// executer.c
void	executer(char *command, char **envp);

// utils.c
char	**free_dbl_ptr(char **ptr);
char	**split_cmd(char *cmd);
char	*get_cmd_path(char *cmd, char **envp);

#endif