
NAME=generator
# CFLAGS= -Wall -Werror -Wextra
SRCS=	generateur.c \
		get_next_line_v3/get_next_line_bonus.c \
		get_next_line_v3/get_next_line_utils_bonus.c

SRCS_OBJ= $(SRCS:.c=.o)

MIN = -500
MAX = 500
R_STAR = 2
R_END = 2500
RATIO= 0.3

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	@$(CC) $(CFLAGS) $(SRCS_OBJ) -L../lib -lft -o $(NAME)

r: $(NAME)
	@./$(NAME)

clean:
	rm -f $(SRCS_OBJ)

fclean: clean
	rm -rf $(NAME)

generate:
	node generateur.js

.PHONY: generate fclean clean all


