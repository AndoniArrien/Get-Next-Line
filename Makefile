NAME = gnl.a
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=10

all: $(NAME)

$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
