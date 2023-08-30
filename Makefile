NAME = so_long
CC = gcc
FLAGS = -Wall -Wextra -Werror 

MLX = ./mlx/libmlx.a
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
GNL = ./get_next_line/gnl.a

all : $(NAME)

$(NAME): $(MLX) *.o $(LIBFT) $(GNL) $(PRINTF)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(MLX) $(LIBFT) $(GNL) $(PRINTF) -o $(NAME) *.o

*.o : *.c
	$(CC) $(FLAGS) -c *.c

$(MLX):
	@make -C ./mlx

$(LIBFT):
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

$(GNL):
	@make -C ./get_next_line

clean:
	rm -rf *.o
	@make clean -C ./ft_printf
	@make clean -C ./mlx
	@make clean -C ./libft
	@make clean -C ./get_next_line

fclean : clean
	rm -rf so_long

re : fclean all

.PHONY: all fclean clean re