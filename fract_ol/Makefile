SRC = main.c utils.c other_utils.c events.c checks.c fractals.c

OBJ = $(SRC:%.c=%.o)

NAME = fract'ol

CC = GCC

CFLAGS = -Wall -Wextra -Werror

NAME = fractal

all: $(NAME)
$(NAME) :
	make -C printf
	gcc  -Lmlx -lmlx -Lprintf -lftprintf -framework OpenGL -framework AppKit $(SRC) -o fractal
clean:
	@make -C printf clean
	@rm -f $(OBJ)

fclean: clean
	@make -C printf fclean
	rm -f $(NAME)

re: fclean all
