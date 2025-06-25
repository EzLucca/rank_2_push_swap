NAME = push_swap
NAME_BONUS = checker_bonus

DIR_LIBFT = ./lib/libft
DIR_SRC = .
DIR_BONUS = bonus
DIR_OBJ = $(DIR_SRC)/objects
DIR_OBJ_BONUS = $(DIR_OBJ)/objects_bonus

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -g -O0 
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft

SOURCES = main.c \
		  check_data.c \
		  check_errors.c \
		  executions_choice.c \
		  moves_push.c \
		  moves_reverse.c \
		  moves_rotate.c \
		  moves_swap.c \
		  operations.c \
		  sort.c \
		  stacks_op.c \
		  utils.c \

BONUS_SRC = $(DIR_BONUS)/checker_bonus.c \
			check_data.c \
			check_errors.c \
			executions_choice.c \
			moves_push.c \
			moves_reverse.c \
			moves_rotate.c \
			moves_swap.c \
			operations.c \
			sort.c \
			stacks_op.c \
			utils.c \

SRC = $(addprefix $(DIR_SRC)/, $(SOURCES))

OBJECTS = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

HEADERS = -I ./include -I $(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)/libft.a

RM = rm -rf

# Define colors
GREEN=\033[0;32m
NC=\033[0m

# === BONUS RULE ===
BONUS_OBJ = $(BONUS_SRC:%.c=$(DIR_OBJ_BONUS)/%.o)

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
	@echo "📁 Directory for the $(NAME) created successfully! 🎉"

teste:
	@echo "📁 Creating directory for $(NAME_BONUS) objects! 🎉"

$(DIR_OBJ_BONUS)/%.o: %.c | teste
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "... 🛠️ compiling $<"

bonus: $(LIBFT) $(BONUS_OBJ)
	@$(COMPILER) $(CFLAGS) $(BONUS_OBJ) -o $(NAME_BONUS) $(LIBFT_FLAGS)
	@echo "✅ Build $(GREEN) $(NAME_BONUS) $(NC) successfully! 🎉"

clean:
	@$(RM) $(DIR_OBJ) 
	@make --no-print-directory clean -C $(DIR_LIBFT)
	@echo "🧹 Removed objects. -> 🗑️"

fclean: clean
	@$(RM) $(NAME)
	@make --no-print-directory fclean -C $(DIR_LIBFT)
	@echo "🧹 Removed executables. -> 🗑️ "

re: fclean all

.PHONY: all clean fclean re
