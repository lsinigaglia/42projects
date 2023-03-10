SRC = Mandelbrot.c Mandelbrot_utils.c events.c

OBC = $(SRC:%.c=%.o)

NAME = fract'ol

CC = GCC

CFLAGS = -Wall -Wextra -Werror

NAME = fract'ol

$(NAME) :
	gcc -g -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRC)
