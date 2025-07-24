# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kreys <kreys@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 16:18:43 by rbourgea          #+#    #+#              #
#    Updated: 2025/07/24 22:41:36 by kreys            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= do-op

SRC			= putnbr.c \
				do-op.c \
				ft_atoi.c \
				operations.c

DIR			= ./srcs/

OBJS		= ${addprefix ${DIR}, ${SRC:.c=.o}}

CFLAGS		= -Wall -Wextra -Werror

CC			= cc

all:		${NAME}

.c.o:
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			@echo Done

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re