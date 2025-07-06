SRC			= srcs/main.c

OBJS		= ${SRC:.c=.o}

NAME		= ft_cat

RM			= rm -f

CC			= cc

FLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				${CC} ${FLAGS} ${OBJS} -o ${NAME} 

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
