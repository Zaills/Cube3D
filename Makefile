NAME=cubed
CC=cc
CFLAGS=-Wall -Werror -Wextra -g
LIBFT=-L ./libft -lft
INCLUDE=-Iheaders/

FILES= src/main.c\
		src/utils.c\
	src/map/open_file.c \
	src/map/check_map.c\
	src/map/check_closed.c \
	src/map/cub_to_cubed.c \
	src/data_init.c\
	src/debug.c\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC)  -c $(CFLAGS) $(INCLUDE) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(OBJ) $(INCLUDE) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ../libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ../libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
