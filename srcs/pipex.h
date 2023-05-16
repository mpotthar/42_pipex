/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:08:05 by mpotthar          #+#    #+#             */
/*   Updated: 2023/05/16 10:08:26 by mpotthar         ###   ########.fr       */
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
# include <stdbool.h>

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
# define ERR_DUP2 "Error: dup2 failed\n"

// functions

// error.c
int		msg_stderr(char *err);
void	msg_error(char *err);
bool	ft_error_ret_true(char *err);
int		msg_fork_error(int *fd, int *p_fd);

// processes.c
void	child_1(char **argv, int *p_fd, char **envp, int *fd);
void	child_2(char **argv, int *p_fd, char **envp, int *fd);

// executer.c
void	executer(char *command, char **envp);

// utils.c
char	**free_dbl_ptr(char **ptr);
char	*get_cmd_path(char *cmd, char **envp);

// count_elements.c
bool	ft_check_equal_quote_amt(char *s);
int		ft_skip_quote_block(char *cmd_line, int *i, bool *split);
int		ft_skip_to_next_delimiter(char *cmd_line, int *i, bool *split, char c);
int		ft_count_cmd_line_elements(char *cmd_line, char c);

// ft_get_cmd_line_elements.c
char	**ft_get_cmd_line_elements(char *cmd_line);

// remove_quotes.c
char	**ft_remove_quotes_from_elements(char **splitted_cmd_line);

#endif