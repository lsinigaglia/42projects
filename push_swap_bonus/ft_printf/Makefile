# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:49:23 by lsinigag          #+#    #+#              #
#    Updated: 2023/03/24 16:26:14 by lsinigag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = funzioni.c funzionialtre.c ft_printf.c
OBJ = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -I.
CC = gcc -g


$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all
