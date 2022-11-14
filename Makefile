# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedrano <lmedrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:01:06 by lmedrano          #+#    #+#              #
#    Updated: 2022/11/14 11:05:36 by lmedrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= get_next_line.c get_next_line_utils.c

OBJS		= ${SRCS:.c=.o}

NAME		= libgnl.a

CC		= cc

CFLAGS		= -Wall -Werror -Wextra

LIB		= ar rc

RM		= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
		${RM} ${NAME}

fclean:		clean
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
