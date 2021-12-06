NAME=lib.a
CC=gcc
CFLAGS=-Wall -Werror -Wextra
SRCS= man_server.c 
SRCS1= man_client.c 
BONUS_SRC= bonus_server.c
BONUS_SRC1= bonus_client.c
SERVER = server
CLIENT = client
OBJS=${SRCS:.c=.o}
OBJS1 = ${SRCS1:.c=.o}
OBJS_BONUS= ${BONUS_SRC:.c=.o}
OBJS_BONUS1=${BONUS_SRC1:.c=.o}
RM = rm -rf
LIBRARY = make -C ./ft_printf 

all: $(NAME)

$(NAME) : ${OBJS} $(OBJS1) $(OBJS_BONUS) $(OBJS_BONUS1)
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a $(NAME)
	$(CC) $(CFLAGS) ${OBJS} -o $(SERVER) $(NAME)
	$(CC) $(CFLAGS) ${OBJS1} -o $(CLIENT) $(NAME)

$(SERVER): $(OBJS)
	gcc -o $(SERVER) $(CFLAGS) $(OBJS) $(NAME)

$(CLIENT): $(OBJS1)
	gcc -o $(CLIENT) $(CFLAGS) $(OBJS1) $(NAME)

bonus:
	$(CC) $(CFLAGS) ${OBJS_BONUS} -o bonus_server $(NAME)
	$(CC) $(CFLAGS) ${OBJS_BONUS1} -o bonus_client $(NAME)

clean:
	find . -type f -name "*.o"  -delete

fclean: clean
	${RM} $(SERVER) $(CLIENT) bonus_server bonus_client
	find . -type f -name "*.a" -delete

re: fclean all

.PHONY:	all clean fclean re
