NAME			= pipex
				
LIBFT			= libft

SRCDIR			= srcs

SRCS			= ${addprefix ${SRCDIR}/, main.c \
					error.c \
					utils.c \
					utils_split.c \
					executer.c \
					processes.c}

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

OBJS			= ${SRCS:.c=.o}

HEADER			= srcs/pipex.h

RM				= rm -f

all:			lib ${NAME}

${NAME}:		${OBJS} ${LIBFT}/libft.a
				${CC} ${CFLAGS} ${OBJS} -L ${LIBFT} -lft -o ${NAME}

${OBJS}:		${HEADER}

lib:
				make -C ${LIBFT} 

clean:	
				${RM} ${OBJS}
				make clean -C ${LIBFT}

fclean:			clean
				${RM} ${NAME}
				make fclean -C ${LIBFT}

re:				fclean all

.PHONY:			all clean fclean re lib

.NOTPARALLEL: