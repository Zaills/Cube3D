NAME=cubed
CC=cc
CCFLAGS=-Wall -Werror -Wextra
FILES=main.c\

OBJ=$(FILES:.c=.o)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
