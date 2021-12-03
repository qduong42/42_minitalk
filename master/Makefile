# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2021/11/30 02:24:49 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#This makefile will compile executable if 4 listed variables bellow are correct#

#---- Update bellow -----------------------------------------------#

CLIENT = client#    Client C file name without file extention #
SERVER = server#    Server C file name without file extention #
LIBFT_DIR = libft/#      libft location                            #
PRINTF_DIR = printf/#    printf location                           #

#---- Update above ------------------------------------------------#

NAME1 = client # client program name output #
NAME2 = server # server program name output #

CLIENT_OBJ = $(CLIENT).o
SERVER_OBJ = $(SERVER).o
SERVER_CH_OBJ = $(SERVER)_ch.o
CLIENT_CH_OBJ = $(CLIENT)_ch.o
CLIENT_C = $(CLIENT).c
SERVER_C = $(SERVER).c
SERVER_CH_C = $(SERVER)_ch.c
CLIENT_CH_C = $(CLIENT)_ch.c

all:	
	test -f $(LIBFT_DIR)libft.a || make re -C $(LIBFT_DIR)
	test -f $(PRINTF_DIR)libftprintf.a || make re -C $(PRINTF_DIR)
	gcc -c $(CLIENT_C)
	gcc $(CLIENT_OBJ) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -I $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME1)
	gcc -c $(SERVER_C)
	gcc $(SERVER_OBJ) -I  $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME2)
	rm $(SERVER_OBJ)
	rm $(CLIENT_OBJ)
	test -f $(PRINTF_DIR)libftprintf.a || make clean -C $(PRINTF_DIR)
	test -f $(LIBFT_DIR)libft.a || make clean -C $(LIBFT_DIR)

re:
	rm $(NAME1)
	rm $(NAME2)
	test -f $(LIBFT_DIR)libft.a || make re -C $(LIBFT_DIR)
	test -f $(PRINTF_DIR)libftprintf.a || make re -C $(PRINTF_DIR)
	gcc -c $(CLIENT_C)
	gcc $(CLIENT_OBJ) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -I $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME1)
	gcc -c $(SERVER_C)
	gcc $(SERVER_OBJ) -I  $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME2)
	rm $(SERVER_OBJ)
	rm $(CLIENT_OBJ)
	test -f $(PRINTF_DIR)libftprintf.a || make clean -C $(PRINTF_DIR)
	test -f $(LIBFT_DIR)libft.a || make clean -C $(LIBFT_DIR)

libup:
	make re -C $(LIBFT_DIR)
	make re -C $(PRINTF_DIR)
	gcc -c $(CLIENT_C)
	gcc $(CLIENT_OBJ) -I $(LIBFT_DIR)libft.h $(LIBFT_DIR)libft.a -I $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME1)
	gcc -c $(SERVER_C)
	gcc $(SERVER_OBJ) -I $(PRINTF_DIR)ft_printf.h $(PRINTF_DIR)libftprintf.a -o $(NAME2)
	rm $(SERVER_OBJ)
	rm $(CLIENT_OBJ)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
gitpush:
	git add * || git commit -m "fast_update" || git push

.PHONY: ch libup