NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS= ft_printf.c convert_write_hexa.c convert_write_deca.c conversion.c
OBJS=${SRCS:.c=.o}
RM = rm -rf

all: $(NAME)

$(NAME) : ${OBJS}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ${OBJS}

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	${RM} */*.o

fclean: clean
	${RM} $(NAME)
	${RM} libft/libft.a

re: fclean all

.PHONY:	all clean fclean re

no: ${SRCS}
	norminette ${SRCS} libft/*.c

git add: ${SRCS}
	git add ${SRCS} libft ft_printf.h Makefile