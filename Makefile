NAME=push_swap
NAME_ASSER=assertion/push_swap_assert
CC=cc 
CFLAGS= -Wall -Wextra -Werror -g
SRCS= 	srcs/main.c \
		srcs/check_and_init.c \
		srcs/move/movement.c \
		srcs/utils/utils_1.c \
		srcs/utils/min_at_beginning.c \
		srcs/utils/display.c \
		srcs/utils/debbuging.c \
		srcs/algo/three.c \
		srcs/algo/five.c
SRCS_ASSERT= 	assertion/assertion.c \
				assertion/algo_assertion.c \
				assertion/init_and_check_assertions.c \
				assertion/move_assertions.c \
				srcs/check_and_init.c \
				srcs/move/movement.c \
				srcs/utils/utils_1.c \
				srcs/utils/min_at_beginning.c \
				srcs/utils/debbuging.c \
				srcs/utils/display.c \
				srcs/algo/three.c \
				srcs/algo/five.c

SRCS_OBJS=$(SRCS:.c=.o)
ASSERT_OBJS=$(SRCS_ASSERT:.c=.o)
LIBFT=lib
VALGRIND_LOG=valgrind.log
OS=$(shell uname)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_OBJS) -Llib -lft -o $(NAME)


#ARG1="--simple 10 -1 32 45 7 89 -23 56 0 14 67 -45 23 9 100 -12 38 72 -8 5 91 -34   60 11 -99 27 44 -6 3 81 19 -50 66 2 77 -15 8 39 -2 95 53 -7 21 64 -30 12 88 -4 6 41 73 -18 25 97 -11 1 58 -22 36 84 -3 13 70 -40 16 92 -14 28 54 -9 4 80 -27 33 68 -5 17 90 -16 42 61 -35 24 79 -13 31   55   -20   69   86   -10   15   37   -28   62   93   -17   26   48   -21"
#ARG2="10 -1 32 45 7 89 -23 56 0 14 67 -45 23 9 100 -12 38 72 -8 5 91 -34   60 11 -99 27 44 -6 3 81 19 -50 66 2 77 -15 8 39 -2 95 53 -7 21 64 -30 12 88 -4 6 41 73 -18 25 97 -11 1 58 -22 36 84 -3 13 70 -40 16 92 -14 28 54 -9 4 80 -27 33 68 -5 17 90 -16 42 61 -35 24 79 -13 31   55   -20   69   86   -10   15   37   -28   62   93   -17   26   48   -21"

L100="12 5 4 3 2"
ARG=$(L100)

as: $(ASSERT_OBJS)
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) $(ASSERT_OBJS) -Llib -lft -o $(NAME_ASSER)
ifeq ($(shell uname), Darwin)
#/* @leaks -q  -atExit -- 
	@./$(NAME_ASSER) $(ARG)
endif
ifeq ($(OS), Linux)
	valgrind --leak-check=full  --leak-resolution=high --log-file=$(VALGRIND_LOG) ./$(NAME_ASSER) $(ARG)
endif

LLDB_SRCS= lldb_training/lldb.c srcs/utils.c
LLDB_OBJS=  $(LLDB_SRCS:.c=.o)

lldb: $(LLDB_OBJS)
	$(CC) $(CFLAGS) $(LLDB_OBJS) -Llib -lft -o lldb_training/lldb_test
	./lldb_training/lldb_test
#lldb lldb_training/lldb_test


clean:
	rm -rf $(SRCS_OBJS) $(ASSERT_OBJS) $(VALGRIND_LOG) $(LLDB_OBJS)

fclean: clean
	make fclean -C $(LIBFT)
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