# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsinigag <lsinigag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:21:19 by lsinigag          #+#    #+#              #
#    Updated: 2023/01/30 22:32:11 by lsinigag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = \
	./ft_memset.c	\
	./ft_bzero.c	\
	./ft_memcpy.c	\
	./ft_memmove.c	\
	./ft_memchr.c	\
	./ft_memcmp.c	\
	./ft_strlen.c	\
	./ft_strlcpy.c	\
	./ft_strlcat.c	\
	./ft_strchr.c	\
	./ft_strrchr.c	\
	./ft_strncmp.c	\
	./ft_strnstr.c  \
	./ft_strdup.c	\
	./ft_calloc.c	\
	./ft_isdigit.c	\
	./ft_atoi.c		\
	./ft_isalpha.c	\
	./ft_isalnum.c	\
	./ft_isascii.c	\
	./ft_isprint.c	\
	./ft_toupper.c	\
	./ft_tolower.c  \
	./ft_substr.c \
	./ft_strjoin.c	\
	./ft_strtrim.c	\
	./ft_split.c	\
	./ft_itoa.c		\
	./ft_strmapi.c	\
	./ft_striteri.c \
	./ft_putchar_fd.c	\
	./ft_putstr_fd.c	\
	./ft_putendl_fd.c	\
	./ft_putnbr_fd.c
SRCBONUS = ./ft_lstnew.c \
	./ft_lstadd_front.c \
	./ft_lstsize.c \
	./ft_lstlast.c \
	./ft_lstadd_back.c \
	./ft_lstdelone.c \
	./ft_lstclear.c \
	./ft_lstiter.c \
	./ft_lstmap.c
OBJBONUS = $(SRCBONUS:%.c=%.o)
OBJ = $(SRC:%.c=%.o)
FLAGS = -Wall -Wextra -Werror


$(NAME) :
	gcc -c $(FLAGS) $(SRC) -I.
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

bonus : $(NAME)
	gcc -c $(FLAGS) $(SRCBONUS) -I.
	ar rcs $(NAME) $(OBJBONUS)
clean :
	rm -f $(OBJ) $(OBJBONUS)

fclean : clean
	rm -f $(NAME)
