SRC			= main.c file_work.c ft_atoi.c tail_f.c str_work.c handl_error.c

DIR			= ./srcs/
OBJS		= ${addprefix ${DIR}, ${SRC:.c=.o}}


NAME		= ft_tail

RM			= rm -f

CC			= cc

FLAGS		= -Wall -Wextra -Werror -fsanitize=address

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
