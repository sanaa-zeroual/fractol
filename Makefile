NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror  
LDFLAGS = -lmlx -lXext -lX11 -lm 

SRC = main.c julia.c mandelbrot.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
