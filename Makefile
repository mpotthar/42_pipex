NAME			= pipex
				
LIBFT			= libft

SRCDIR			= srcs

SRCS			= ${addprefix ${SRCDIR}/, main.c}

OBJS			= ${SRCS:.c=.o}

CC				= cc

# CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

# Colors
GREEN			= \033[92m
YELLOW			= \033[0;33m
MAGENTA			= \033[0;35m
ESCAPE			= \033[0m

all:			lib ${NAME}

%.o: %.c		
				@${CC} ${CFLAGS} -c $^ -o $@

${NAME}:		start ${OBJS} ${LIBFT}/libft.a
				@${CC} ${CFLAGS} ${OBJS} -L ${LIBFT} -lft -o ${NAME}
				@echo "${GREEN}******************   COMPILED  ******************${ESCAPE}"
				@echo "${MAGENTA}******************     DONE    ******************${ESCAPE}"
				@echo " "

lib:
				@make bonus -C ${LIBFT} > /dev/null 2>&1	

start:			
				@echo " "
				@echo "-------------------------------------------------"
				@echo "${MAGENTA}******************    PIPEX    ******************${ESCAPE}"
				@echo "-------------------------------------------------"
				@echo " "
				@echo "${YELLOW}******************  COMPILING  ******************${ESCAPE}"

clean:	
				@${RM} ${OBJS}
				@make clean -C ${LIBFT} > /dev/null 2>&1
				@echo "${GREEN}*******************  CLEANED  *******************${ESCAPE}"

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C ${LIBFT} > /dev/null 2>&1

re:				fclean all

.PHONY:			all start clean fclean re