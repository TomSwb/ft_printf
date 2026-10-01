
NAME = libft.a

SOURCES = ${PART1} ${PART2} ${PART3}
		
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