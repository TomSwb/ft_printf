# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/12 16:35:33 by tschwab           #+#    #+#              #
#    Updated: 2026/10/15 14:48:56 by tschwab          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c \
		ft_printf_managers.c \
		ft_printf_parsing.c \
		ft_printf_parsing_utils.c \
		ft_printf_printing.c \
		ft_printf_printing_utils.c \
		ft_printf_len_utils.c

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJECTS = ${SOURCES:.c=.o}

AR = ar -rcs

RM = rm -f

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

clean:
		${RM} ${OBJECTS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re