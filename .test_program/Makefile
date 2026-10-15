# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tschwab <tschwab@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/15 14:55:07 by tschwab           #+#    #+#              #
#    Updated: 2026/10/15 14:58:29 by tschwab          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME		= test_printf

SOURCES		= main.c \
			  test_char.c \
			  test_deci.c \
			  test_hexa.c \
			  test_ptr.c \
			  ft_printf.c \
			  ft_printf_managers.c \
			  ft_printf_parsing.c \
			  ft_printf_parsing_utils.c \
			  ft_printf_printing.c \
			  ft_printf_printing_utils.c \
			  ft_printf_len_utils.c

OBJECTS		= $(SOURCES:.c=.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus