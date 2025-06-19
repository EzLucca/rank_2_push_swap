
NAME = push_swap

DIR_LIB = ./library/libft
DIR_SRC = .
DIR_OBJ = $(DIR_SRC)/objects

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_FLAGS = -L $(DIR_LIB) -lft

SOURCES = check_data.c \
		  check_errors.c \
		  executions_choice.c \
		  main.c \
		  moves_push.c \
		  moves_reverse.c \
		  moves_rotate.c \
		  moves_swap.c \
		  operations_a.c \
		  operations_b.c \
		  sort.c \
		  stacks_op.c \
		  utils.c \

SRC = $(addprefix $(DIR_SRC)/, $(SOURCES))

OBJECTS = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

HEADERS = -I ./includes -I $(DIR_LIB)

LIBFT = $(DIR_LIB)/libft.a

RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(DIR_LIB)

$(NAME): $(OBJECTS)
	@$(COMPILER) $(CFLAGS) $(OBJECTS) -o $@  $(LIBFT_FLAGS)
	@echo "$(NAME) was created"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "compiling $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@echo "Making directory for $(NAME) objects"

clean:
	@$(RM) $(DIR_OBJ)
	@make clean -C $(DIR_LIB)
	@echo "Objects of $(NAME) are removed!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(DIR_LIB)
	@echo "Executable $(NAME) is removed!"

re: fclean all

.PHONY: all clean fclean re
