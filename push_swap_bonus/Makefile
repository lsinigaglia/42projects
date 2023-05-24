NAME = a.out
SRC = main.c base_functions.c input_check.c starting.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c make_move.c \
lists_functions.c base_functions1.c base_functions2.c
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
