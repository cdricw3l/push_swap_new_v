NAME=push_swap
NAME_ASSER=assertion/push_swap_assert
CC=cc 
CFLAGS= -Wall -Wextra -Werror
SRCS=push_swap.c main.c
SRCS_ASSERT= assertion/assertion.c push_swap.c 
SRCS_OBJS=$(SRCS:.c=.o)
ASSERT_OBJS=$(SRCS_ASSERT:.c=.o)
LIBFT=libft

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -Llibft -lft -o $(NAME)

as: $(ASSERT_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(ASSERT_OBJS) -Llibft -lft -o $(NAME_ASSER)
	./$(NAME_ASSER)

clean:
	rm -rf $(SRCS_OBJS) $(ASSERT_OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_ASSER)

re: fclean $(NAME)

COM=push_swap_generic

git: fclean
	git add .
	git commit -m $(COM)
	git push origin $(shell git branch --show-current)

.PHONY: all clean fclean re as