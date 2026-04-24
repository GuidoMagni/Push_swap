# Standard
NAME = push_swap

# Directories
OBJ_DIR = obj/

# Compiler and CFlags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -rf

# Source files
SRCS = a_to_b.c b_to_a.c errors.c init_stack.c push.c push_swap.c rotate.c rrotate.c sort.c sort_utils.c split.c swap.c utils.c

OBJ = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:
	@$(MAKE) all

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: start all clean fclean re
