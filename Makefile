
NAME = push_swap

DIR_LIB = ./library/libft
DIR_SRC = .
DIR_OBJ = $(DIR_SRC)/objects

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L $(DIR_LIB) -lft

SOURCES = check_data.c \
		  check_error.c \
		  executions_choice.c \
		  main.c \
		  moves_push.c \
		  moves_reverse.c \
		  moves_rotate.c \
		  moves_swap.c \
		  operations.c \
		  sort.c \
		  stacks_op.c \
		  utils.c \

SRC = $(addprefix $(DIR_SRC)/, $(SOURCES))

OBJECTS = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SOURCES)))

HEADERS = -I ./includes -I $(DIR_LIB)

LIBFT = $(DIR_LIB)/libft.a

RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(DIR_LIB)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(HEADERS) -o $@
	@echo "push_swap concluded"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "compiling $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean:
	@$(RM) $(DIR_OBJ)
	@make clean -C $(DIR_LIB)
	@echo "deleted objects files"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(DIR_LIB)
	@echo "deleted objects files and executables"

re: fclean all

.PHONY: all clean fclean re
