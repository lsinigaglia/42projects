NAME = a.out
SRC = main.c base_functions.c utils.c lists_functions.c starting.c basic_sorts.c lets_push_swap.c get_positions.c
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
prova : FAKEmain.o lists_functions.o
	gcc FAKEmain.c lists_functions.c base_functions.c ./libft/libft.a ./ft_printf/libftprintf.a -o prova
clean :

	@rm -f $(NAME)

fclean : clean
	@make fclean -C ft_printf
	@make fclean -C libft
	@rm -f $(OBJ) $(NAME)
re : clean all
