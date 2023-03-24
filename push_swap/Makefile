NAME = push_swap
SRC = PROVEmain.c base_functions.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra
LIBS = -Lft_printf -lftprintf -Llibft -lft


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ft_printf
	@make -C libft
	$(CC) $(FLAGS) $(LIBS) $(OBJ) -o $(NAME) -I.
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@rm -f $(NAME)

fclean : clean
	@rm -f $(OBJ)

re : fclean all
