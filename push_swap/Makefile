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
	$(CC) $(CFLAGS) -I. $(OBJ) $(LIBS) -o $(NAME) 
%.o: %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@
clean :

	@rm -f $(NAME)

fclean : clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)
re : clean all
