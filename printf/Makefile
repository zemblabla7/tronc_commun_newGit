
NAME = libftprintf.a
FILES = ft_printf.c \
		is_char.c	\
		is_num.c	\

OBJS = ${FILES:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.o .c:
	cc -Wall -Werror -Wextra ${OBJS}

.Phony : all, clean, fclean, re, bonus


