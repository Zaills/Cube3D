NAME=cubed
CC=cc
CCFLAGS=-Wall -Werror -Wextra -g
LIBFT=-L ./libft -lft

FILES= src/main.c\
		src/utils.c\
	src/map/open_file.c \
	src/map/cub_to_cubed.c \
	src/data_init.c\
	src/debug.c\


OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ../libft
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ../libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
