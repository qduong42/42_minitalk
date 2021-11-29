# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emomkus <emomkus@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 17:47:09 by emomkus           #+#    #+#              #
#    Updated: 2021/11/22 22:29:09 by emomkus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OPTION = -c

SRC = ft_printf.c ft_printaddr.c ft_printchar.c ft_printhex.c ft_printhexu.c \
	ft_printuint.c ft_printstr.c ft_printint.c

OBJ = ft_printf.o ft_printaddr.o ft_printchar.o ft_printhex.o ft_printhexu.o \
	ft_printuint.o ft_printstr.o ft_printint.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(OPTION) $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	
fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:		fclean all

.PHONY:			all clean fclean
