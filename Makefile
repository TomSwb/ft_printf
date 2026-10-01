
NAME = libftprintf.a

SOURCES = ft_printf.c \
		ft_printf_managers.c \
		ft_printf_parsing.c \
		ft_printf_parsing_utils.c \
		ft_printf_printing.c \
		ft_printf_printing_utils.c \
		ft_printf_len_utils.c
		
CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJECTS = ${SOURCES:.c=.o}

AR = ar -rcs

RM = rm -f

%.o: %.c libft.h
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