NAME=push_swap
NAME_ASSER=assertion/push_swap_assert
CC=cc 
CFLAGS= -Wall -Wextra -Werror -g
SRCS= 	srcs/main.c \
		srcs/initialisation/check_and_init.c \
		srcs/move/movement.c \
		srcs/move/at_beginning.c \
		srcs/utils/utils_1.c \
		srcs/utils/display.c \
		srcs/utils/debbuging.c \
		srcs/algo/three.c \
		srcs/algo/five.c \
		srcs/algo/On√n.c \
		srcs/algo/sorting_values.c 
SRCS_ASSERT= 	assertion/assertion.c \
				assertion/algo_assertion.c \
				assertion/init_and_check_assertions.c \
				assertion/move_assertions.c \
				srcs/initialisation/check_and_init.c \
				srcs/move/movement.c \
				srcs/move/at_beginning.c \
				srcs/utils/utils_1.c \
				srcs/utils/debbuging.c \
				srcs/utils/display.c \
				srcs/algo/three.c \
				srcs/algo/five.c \
				srcs/algo/On√n.c 

SRCS_OBJS=$(SRCS:.c=.o)
ASSERT_OBJS=$(SRCS_ASSERT:.c=.o)
LIBFT=lib
VALGRIND_LOG=valgrind.log
OS=$(shell uname)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -Llib -lft -o $(NAME)

# simple algo #
ARG_SIMPLE="-126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631"
simple: $(NAME)
	./push_swap --simple $(ARG_SIMPLE) | ./checker/checker_linux $(ARG_SIMPLE)

# simple algo #
ARG_SIMPLE="-126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631"
middle: $(NAME)
	@./push_swap --middle $(ARG_SIMPLE) | ./checker/checker_linux $(ARG_SIMPLE)

as: $(ASSERT_OBJS)
	$(CC) $(CFLAGS) $(ASSERT_OBJS) -Llib -lft -o $(NAME_ASSER)
ifeq ($(shell uname), Darwin)
#/* @leaks -q  -atExit -- 
	@./$(NAME_ASSER) $(ARG)
endif
ifeq ($(OS), Linux)
	valgrind --leak-check=full  --leak-resolution=high --log-file=$(VALGRIND_LOG) ./$(NAME_ASSER) $(ARG)
endif

LLDB_SRCS= lldb_training/lldb.c \
			srcs/initialisation/check_and_init.c \
			srcs/move/movement.c \
			srcs/move/at_beginning.c \
			srcs/utils/utils_1.c \
			srcs/utils/debbuging.c \
			srcs/utils/display.c \
			srcs/algo/three.c \
			srcs/algo/five.c \
			srcs/algo/On√n.c 
LLDB_OBJS=  $(LLDB_SRCS:.c=.o)

lldb: $(LLDB_OBJS)
	$(CC) $(CFLAGS) $(LLDB_OBJS) -Llib -lft -o lldb_training/lldb_test
	./lldb_training/lldb_test
#lldb lldb_training/lldb_test


clean:
	rm -rf $(SRCS_OBJS) $(ASSERT_OBJS) $(VALGRIND_LOG) $(LLDB_OBJS)

fclean: clean
	rm -rf $(NAME) $(NAME_ASSER) lldb_training/lldb_test 

re: fclean $(NAME)

COM=push_swap_generic

git: fclean
	git add .
	git commit -m $(COM)
	git push origin $(shell git branch --show-current)

libft:
	rm -rf lib/*
	make -C $(LIBFT)
	cp $(LIBFT)/libft.* lib/.
	make clean -C $(LIBFT)

.PHONY: all clean fclean re as home libft git lldb