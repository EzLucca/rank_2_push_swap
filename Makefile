
NAME = push_swap

DIR_LIBFT = ./lib/libft
DIR_SRC = .
DIR_OBJ = $(DIR_SRC)/objects

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft

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

HEADERS = -I ./includes -I $(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)/libft.a

RM = rm -rf

# Define colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make --no-print-directory -C $(DIR_LIBFT)

$(NAME): $(OBJECTS)
	@$(COMPILER) $(CFLAGS) $(OBJECTS) -o $@  $(LIBFT_FLAGS)
	@echo "✅ Build $(GREEN)$(NAME) $(NC)successfully! 🎉"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "... 🛠️ compiling $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@echo "📁 Creating directory for $(NAME) objects"

clean:
	@$(RM) $(DIR_OBJ)
	@make --no-print-directory clean -C $(DIR_LIBFT)
	@echo "🧹 Objects of $(NAME) are removed! -> 🗑️"

fclean: clean
	@$(RM) $(NAME)
	@make --no-print-directory fclean -C $(DIR_LIBFT)
	@echo "🧹 Executable $(NAME) is removed! -> 🗑️ "

re: fclean all

.PHONY: all clean fclean re
