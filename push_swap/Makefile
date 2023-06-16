NAME = push_swap
SRC = main.c base_functions.c utils.c lists_functions.c starting.c basic_sorts.c lets_push_swap.c get_positions.c \
cheap_move.c input_check.c base_functions_1.c base_functions_2.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Werror -Wall -Wextra
LIBS = -Lft_printf -lftprintf -Llibft -lft


all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) -I. $(OBJ) $(LIBS) -o $(NAME)
%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@
clean :

	@rm -f $(NAME)

fclean : clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)
re : clean all
