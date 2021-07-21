# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 12:53:49 by rcheiko           #+#    #+#              #
#    Updated: 2021/03/10 15:35:45 by rcheiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	fill_base.c \
				fill_struct_1.c \
				fill_struct_type.c \
				fonction_mere.c \
				ft_itoa.c \
				ft_printf.c \
				trait_c_pour.c \
				trait_int.c \
				trait_int_2.c \
				trait_int_3.c \
				trait_p.c \
				trait_s.c \
				utils_1.c \
				utils_2.c \
				utils_3.c


OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I./includes

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
