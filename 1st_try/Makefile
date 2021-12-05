NAME=lib.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS= man_server.c bonus_server.c
SRCS1= man_client.c bonus_client.c
SERVER = server
CLIENT = client
OBJS=${SRCS:.c=.o}
OBJS1 = ${SRCS1:.c=.o}
RM = rm -rf
LIBRARY = make -C ./ft_printf 

all: $(NAME)

$(NAME) : ${OBJS} $(OBJS1)
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a $(NAME)
	$(CC) -o $(SERVER) $(CFLAGS) $(NAME) ${OBJS}
	$(CC) -o $(CLIENT) $(CFLAGS) $(NAME) ${OBJS1}

$(SERVER): $(OBJS)
	gcc -o $(SERVER) $(CFLAGS) $(OBJS) $(NAME)

$(CLIENT): $(OBJS1)
	gcc -o $(CLIENT) $(CFLAGS) $(OBJS1) $(NAME)
clean:
	${RM} ${OBJS} $(BONUS_OBJS) $(SERVER) $(CLIENT)
	find . -type f -name "*.o"  -delete

fclean: clean
	find . -type f -name "*.a" -delete

re: fclean all

.PHONY:	all clean fclean re

no: ${SRCS}
	norminette ${SRCS} libft/*.c

