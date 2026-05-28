NAME=push_swap
NAME_ASSER=assertion/push_swap_assert
CC=cc 
CFLAGS= -Wall -Wextra -Werror -g
SRCS= 	srcs/main.c \
		srcs/initialisation/check_and_init.c \
		srcs/move/movement.c \
		srcs/move/at_beginning.c \
		srcs/utils/utils_1.c \
		srcs/utils/utils_2.c \
		srcs/utils/display.c \
		srcs/utils/debbuging.c \
		srcs/algo/three.c \
		srcs/algo/five.c \
		srcs/algo/medium.c \
		srcs/algo/sorting_values.c 
SRCS_ASSERT= 	assertion/assertion.c \
				assertion/algo_assertion.c \
				assertion/3_assert.c \
				assertion/5_assert.c \
				assertion/4_assert.c \
				assertion/init_and_check_assertions.c \
				assertion/move_assertions.c \
				assertion/medium_assertion.c \
				assertion/generate_range_assert.c \
				srcs/initialisation/check_and_init.c \
				srcs/move/movement.c \
				srcs/move/at_beginning.c \
				srcs/utils/utils_1.c \
				srcs/utils/utils_2.c \
				srcs/utils/debbuging.c \
				srcs/utils/display.c \
				srcs/algo/three.c \
				srcs/algo/five.c \
				srcs/algo/medium.c 

SRCS_OBJS=$(SRCS:.c=.o)
ASSERT_OBJS=$(SRCS_ASSERT:.c=.o)
LIBFT=lib
VALGRIND_LOG=valgrind.log
OS=$(shell uname)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -Llib -lft -o $(NAME)

# simple algo #
ARG_SIMPLE="-126 -717 -1185 -2219 -2402 -2471 -1055 -3238 -3994 631 -4097 -4456 -4670 505 -4750 -4806 -306 -1082 -1441 -1479 -4864 -2280 1764 -4987 -4990 -700 -1471 -2303 -2978 -4004 -4031 2964 1833 2908 -4280 -4501 1748 1362 1188 -2422 -4550 2818 268 2750 3568 -3816 213 4952 77 1645 -865 -2364 3705 -4122 3206 2490 2603 2418 -977 1300 -1216 925 4910 4813 2816 2671 -1237 2124 901 2091 1533 814 789 4761 4723 678 4569 -1786 1494 4475 574 4373 296 4351 4329 4238 3718 3079 2523 1396 1351 3701 3642 3054 3043 1054 2917 2853 2453 2073"
simple: $(NAME)
	./push_swap --simple $(ARG_SIMPLE) | ./checker/checker_linux $(ARG_SIMPLE)

# simple algo #
ARG_MIDDLE="8 4 2 1 7 14 5 0 11 10 3 19 15 13 20 17 6 18 16 12"
middle: $(NAME)
	./push_swap --medium $(ARG_MIDDLE) 
#| ./checker/checker_linux $(ARG_MIDDLE)

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