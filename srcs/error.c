#include "pipex.h"

int	msg_stderr(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void msg_error(char *err)
{
	perror(err);
	exit (1);
}