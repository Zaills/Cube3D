NAME=cubed
NAME_BONUS=cubed_bonus
CC=cc
CFLAGS=-Wall -Werror -Wextra -g
LIBFT=-L ./libft -lft
MLX42=MLX42/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
INCLUDE=-Iheaders/

MAIN_OBJ=src/render/movement.o\
	src/render/render.o\
	cubed\

BONUS_OBJ=src/render/bonus/minimap.o\
	src/render/bonus/minimap_utils.o\
	src/render/bonus/movement.o\
	src/render/bonus/render.o\
	src/render/bonus/mouse.o\

FILES= src/main.c\
		src/utils.c\
	src/map/open_file.c \
	src/map/close_file.c \
	src/map/check_map.c\
	src/map/check_closed.c \
	src/map/cub_to_cubed.c \
	src/render/render.c\
	src/render/render_utils.c\
	src/render/sky_floor.c\
	src/render/raycast.c\
	src/render/movement.c\
	src/render/movement_utils.c\
	src/render/render_wall.c\
	src/data_init.c\

OBJ=$(FILES:.c=.o)

compile=$(CC) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME)

ifdef BONUS
	compile=$(CC) $(OBJ) $(LIBFT) $(MLX42) -o $(NAME_BONUS)
	FILES=src/main.c\
	src/utils.c\
	src/map/open_file.c \
	src/map/check_map.c\
	src/map/check_closed.c \
	src/map/cub_to_cubed.c \
	src/render/bonus/render.c\
	src/render/bonus/mouse.c\
	src/render/render_utils.c\
	src/render/sky_floor.c\
	src/render/raycast.c\
	src/render/bonus/movement.c\
	src/render/movement_utils.c\
	src/render/render_wall.c\
	src/render/bonus/minimap.c\
	src/render/bonus/minimap_utils.c\
	src/map/close_file.c \
	src/data_init.c\

endif

%.o : %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	cd MLX42 && cmake -B build
	cd MLX42 && cmake --build build -j4
	rm -f $(NAME_BONUS)
	$(MAKE) -C ./libft
	$(compile)

bonus:
	rm -f $(MAIN_OBJ)
	make BONUS=1

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	cd MLX42 && cmake -E remove_directory build
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

rebuild_mlx:
	cd MLX42 && cmake -B build

.PHONY: all re clean fclean rebuild_mlx bonus
