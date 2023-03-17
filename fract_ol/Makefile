SRC = Mandelbrot.c Mandelbrot_utils.c Mandelbrot_other_utils.c events.c checks.c

OBJ = $(SRC:%.c=%.o)

NAME = fract'ol

CC = GCC

CFLAGS = -Wall -Wextra -Werror

NAME = a.out

all: $(NAME)
$(NAME) :
	make -C printf
	gcc -g -Lmlx -lmlx -Lprintf -lftprintf -framework OpenGL -framework AppKit $(SRC) -o a.out
clean:
	@make -C printf clean
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
