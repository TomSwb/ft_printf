# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschwab <tschwab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/12 16:35:33 by tschwab           #+#    #+#              #
#    Updated: 2026/10/12 16:37:35 by tschwab          ###   ########.fr        #
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

%.o: %.c
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