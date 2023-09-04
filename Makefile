NAME=cubed
CC=cc
CFLAGS=-Wall -Werror -Wextra -g
LIBFT=-L ./libft -lft
MLX42=MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
INCLUDE=-Iheaders/

FILES= src/main.c\
		src/utils.c\
	src/map/open_file.c \
	src/map/check_map.c\
	src/map/check_closed.c \
	src/map/cub_to_cubed.c \
	src/render/render.c\
	src/render/render_utils.c\
	src/render/sky_floor.c\
	src/data_init.c\
	src/debug.c\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	cd MLX42 && cmake -E remove_directory build
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

rebuild_mlx:
	cd MLX42 && cmake -B build

.PHONY: all re clean fclean rebuild_mlx
