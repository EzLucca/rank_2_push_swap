# Project Names
NAME = push_swap
NAME_BONUS = checker_bonus

# Directories
DIR_SRC = src
DIR_BONUS = bonus
DIR_OBJ = objects
DIR_LIBFT = lib/libft
DIR_LIBFT_INC = $(DIR_LIBFT)/include

# Compiler & Flags
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
HEADERS = -Iinclude -I$(DIR_LIBFT_INC)
LIBFT_FLAGS = -L$(DIR_LIBFT) -lft
RM = rm -rf

# Source Files
MAIN_SRC = main.c

SHARED_SRC = \
	check_data.c \
	check_errors.c \
	executions_choice.c \
	moves_push.c \
	moves_reverse.c \
	moves_rotate.c \
	moves_swap.c \
	operations_a.c \
	operations_b.c \
	sort.c \
	stacks_op.c \
	utils.c

BONUS_SRC = checker_bonus.c

# Source Paths
SRC = $(addprefix $(DIR_SRC)/, $(MAIN_SRC) $(SHARED_SRC))
BONUS_SRC_FULL = $(addprefix $(DIR_BONUS)/, $(BONUS_SRC))
SHARED_SRC_FULL = $(addprefix $(DIR_SRC)/, $(SHARED_SRC))

# Object Files
OBJECTS = $(SRC:%.c=$(DIR_OBJ)/%.o)
BONUS_OBJ = $(BONUS_SRC_FULL:%.c=$(DIR_OBJ)/%.o)
SHARED_OBJ = $(SHARED_SRC_FULL:%.c=$(DIR_OBJ)/%.o)
ALL_BONUS_OBJ = $(SHARED_OBJ) $(BONUS_OBJ)

# Libft
LIBFT = $(DIR_LIBFT)/libft.a

# Colors
GREEN = \033[0;32m
NC = \033[0m

####################### RULES ########################

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME) $(NAME_BONUS)

$(LIBFT):
	@make --no-print-directory -C $(DIR_LIBFT)

# Push_swap build
$(NAME): $(OBJECTS)
	@$(COMPILER) $(CFLAGS) $(OBJECTS) -o $@ $(LIBFT_FLAGS)
	@echo "✅ Build $(GREEN)$(NAME)$(NC) successfully! 🎉"

# Bonus build
$(NAME_BONUS): $(ALL_BONUS_OBJ)
	@$(COMPILER) $(CFLAGS) $(ALL_BONUS_OBJ) -o $@ $(LIBFT_FLAGS)
	@echo "✅ Build $(GREEN)$(NAME_BONUS)$(NC) successfully! 🎉"

# Compile rule for all object files
$(DIR_OBJ)/%.o: %.c | $(DIR_OBJ)
	@mkdir -p $(dir $@)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "... 🛠️ compiling $<"

# Ensure object dir exists
$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean:
	@$(RM) $(DIR_OBJ)
	@make --no-print-directory clean -C $(DIR_LIBFT)
	@echo "🧹 Cleaned object files."

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@make --no-print-directory fclean -C $(DIR_LIBFT)
	@echo "🧹 Removed executables."

re: fclean all

.PHONY: all bonus clean fclean re
