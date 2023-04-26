/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:01:27 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/26 16:52:01 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// VAR
// ---
// ft_read_line: fd:				filedescriptor 
// ft_read_line: in_file: 			0 = EOF, 1 = in file
// ft_read_line: buffer: 			buffer for read
// ft_read_line: read_return:		return val for read
// ---
// ft_check: remainder:				remaining chars for new line
// ft_check: in_file:				0 = EOF, 1 = in file
// ft_check: line:					current line
// ft_check: spot:					occurence of \n or \0
// ft_check: temp:					temp. ptr for new remainder
// ---
// ft_check_remainder: remainder: 	remaining chars for new line
// ft_check_remainder: fd:			filedescriptor 
// ft_check_remainder: in_file:		0 = EOF, 1 = in file
// ft_check_remainder: line:		current line
// ft_check_remainder: spot:		occurence of \n
// ft_check_remainder: temp:		ptr to new read buffer
// ft_check_remainder: temp2:		ptr to concatenated str of remainder + temp
// ---
// get_next_line: fd:				filedescriptor 
// get_next_line: remainder:		remaining chars for new line
// get_next_line: line:				current line
// get_next_line: in_file:			0 = EOF, 1 = in file
// ---
#include "libft.h"

// FT_READ_LINE
// used when spot not found and still in file
// takes fd and *in_file, reads from file to buffer and returns 
// the buffer. 
char	*ft_read_line(int fd, int *in_file)
{
	char	*buffer;
	int		read_return;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_return = read(fd, buffer, BUFFER_SIZE);
	if (read_return == 0)
		*in_file = 0;
	else if (read_return == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_return] = '\0';
	return (buffer);
}

// FT_CHECK
// used when spot found or eof
// takes the remainder, the in_file pointer, the current line and the
// spot for occurence \n
// if eof search for \0, store address in spot
// create line with remainder, from 0 to end. 
// return line
char	*ft_check(char **remainder, int *in_file, char *line, char *spot)
{
	char	*temp;

	if (*remainder && *in_file == 0)
		spot = ft_strchr(*remainder, '\0');
	line = ft_substr(*remainder, 0, spot - *remainder + *in_file);
	if (!line)
		return (NULL);
	temp = ft_strjoin(spot + *in_file, "");
	if (!temp)
		return (NULL);
	free(*remainder);
	*remainder = temp;
	return (line);
}

// FT_CHECK_REMAINDER
// takes remainder, fd, in_file and line
// if remainder is existing, check for \n and store address in spot
// if no spot found, read next buffer and add to remainder, 
// else: spot found or eof.
// return line
char	*ft_check_remainder(char **remainder, int fd, int *in_file, char *line)
{
	char	*spot;
	char	*temp;
	char	*temp2;

	spot = NULL;
	if (*remainder)
		spot = ft_strchr(*remainder, '\n');
	if (!spot && *in_file == 1)
	{
		temp = ft_read_line(fd, in_file);
		if (!temp)
			return (NULL);
		temp2 = ft_strjoin(*remainder, temp);
		if (!temp2)
			return (NULL);
		free(*remainder);
		free(temp);
		*remainder = temp2;
		line = ft_check_remainder(remainder, fd, in_file, line);
	}
	else
		line = ft_check(remainder, in_file, line, spot);
	return (line);
}

// GET_NEXT_LINE
// takes fd and error-checks it
// if no remainder found read new buffer into it
// set line to the return of ft_check_remainder
// if no new line found, return NULL
// return line
char	*get_next_line(int fd)
{
	static char		*remainder[1024];
	char			*line;
	int				in_file;

	in_file = 1;
	if (fd == -1)
		return (NULL);
	if (remainder[fd] == NULL)
		remainder[fd] = ft_read_line(fd, &in_file);
	line = ft_check_remainder(&remainder[fd], fd, &in_file, NULL);
	if (!line)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
	}
	return (line);
}
