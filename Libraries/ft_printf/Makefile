# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpaci <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 18:46:18 by mpaci             #+#    #+#              #
#    Updated: 2021/03/05 18:46:22 by mpaci            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LIB			= ar -rc

RAN			= ranlib

DIR_SPEC	= spec

SRCS		= ft_printf.c\
				ut_one.c\
				ut_two.c\
				ut_three.c\
				ft_spec_u.c\
				ft_spec_c.c\
				ft_spec_%.c\
				ft_spec_s.c\
				ft_spec_p.c\
				ft_spec_x.c\
				ft_spec_xup.c\
				ft_spec_id.c\
				search.c

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

${NAME}: ${OBJS}
		${LIB} ${NAME} ${OBJS}
		${RAN} ${NAME}

all:	${NAME}

out: 
	@${CC} ${CFLAGS} ${SRCS} && ./a.out
	@${RM} ./a.out

outtino:
		@${CC} ${SRCS} && ./a.out
		@${RM} ./a.out

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re