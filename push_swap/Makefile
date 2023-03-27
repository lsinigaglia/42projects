NAME = a.out
SRC = PROVEmain.c base_functions.c utils_and_ss.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra
LIBS = -Lft_printf -lftprintf -Llibft -lft



all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME) -I.
%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -Ilibft -Ift_printf
clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(OBJ)

re : fclean all
