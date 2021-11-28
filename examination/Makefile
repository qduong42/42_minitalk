# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 00:00:30 by emomkus           #+#    #+#              #
#    Updated: 2021/11/29 00:16:40 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client

all:
	gcc -c client_test.c libft/libft.h libft/ft_atoi.c 
	gcc client_test.o ft_atoi.o -o client
	rm client_test.o
	rm ft_atoi.o

re:
	