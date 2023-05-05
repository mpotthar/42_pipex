/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:05 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/05 16:46:41 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define ERR_INFILE "pipex: input"
# define ERR_OUTFILE "pipex: output"
# define ERR_PIPE "Error: pipe failed\n"
# define ERR_FORK "Error: fork failed\n"
# define ERR_CMDPATH "Error: command not found\n"
# define ERR_EXECVE "Error: execve failed\n"

// functions

// error.c
int		msg_stderr(char *err);
void	msg_error(char *err);

// processes.c
void	child_1(char **argv, int *p_fd, char **envp);
void	child_2(char **argv, int *p_fd, char **envp);

// executer.c
void	executer(char *command, char **envp);

// utils.c
char	**free_dbl_ptr(char **ptr);
char	*get_cmd_path(char *cmd, char **envp);

// utils_split.c
char	**split_cmd(char *cmd);

#endif