NAME = push_swap
BONUS_NAME = checker

DIR_LIBFT = ./lib/libft
DIR_SRC = .
DIR_OBJ = $(DIR_SRC)/objects
DIR_OBJ_BONUS = $(DIR_BONUS)/objects_bonus
DIR_BONUS = ./bonus 

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

BONUS_SOURCES := checker_bonus.c $(SOURCES)

SRC = $(addprefix $(DIR_SRC)/, $(SOURCES))

BONUS_SRC = $(addprefix $(DIR_SRC)/$(DIR_BONUS)/, $(BONUS_SOURCES))

OBJECTS = $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

BONUS_OBJS := $(BONUS_SRC:$(DIR_SRC)/$(DIR_BONUS)/%.c=$(DIR_OBJ_BONUS)/%.o)

HEADERS = -I ./include -I $(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)/libft.a

RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(COMPILER) $(CFLAGS) $(OBJECTS) -o $@  $(LIBFT_FLAGS)
	@echo "$(NAME) was created"

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "compiling $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@echo "Making directory for $(NAME) objects"

$(DIR_OBJ_BONUS):
	@mkdir -p $(DIR_OBJ_BONUS)
	@echo "Making directory for $(BONUS_NAME) objects"

$(DIR_OBJ_BONUS)/%.o: $(DIR_SRC)/$(DIR_BONUS)/%.c | $(DIR_OBJ_BONUS)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compiling bonus $<"

bonus: $(LIBFT) $(DIR_OBJ_BONUS) $(BONUS_NAME)

clean:
	@$(RM) $(DIR_OBJ)
	@make clean -C $(DIR_LIBFT)
	@echo "Objects of $(NAME) are removed!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(DIR_LIBFT)
	@echo "Executable $(NAME) is removed!"

re: fclean all

.PHONY: all clean fclean re
