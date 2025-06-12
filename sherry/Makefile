NAME = push_swap
BONUS = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIB_DIR = lib/libft
LIBFT = $(LIB_DIR)/libft.a

SRCS_DIR = srcs/push_swap/
SRCS_O = operations_combs.c operations_rotate.c operations_swap_push.c process_args.c \
		push_swap_main.c sort_ascending.c sort_caculate_steps_assit.c sort_caculate_steps.c \
		util_basic.c util_stacklist1.c util_stacklist2_find.c
SRCS = $(addprefix $(SRCS_DIR),$(SRCS_O))
OBJS = $(SRCS:.c=.o)

GNL_DIR = lib/get_next_line
GNL = $(GNL_DIR)/gnl

SRCS_B_DIR = srcs/checker/
SRCS_BONUS_O = checker_main_bonus.c operations_rotate_bonus.c operations_swap_push_bonus.c \
		process_args_bonus.c util_basic_bonus.c util_stacklist_bonus.c
SRCS_BONUS = $(addprefix $(SRCS_B_DIR), $(SRCS_BONUS_O))
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus: $(BONUS)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
	@echo "push_swap is generated!"

$(BONUS): $(OBJS_BONUS)
	@make -C $(LIB_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(GNL) -o $@
	@echo "checker is generated!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIB_DIR)
	@make clean -C $(GNL_DIR)
	@echo "push_swap objects are cleaned!"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@make fclean -C $(LIB_DIR)
	@make fclean -C $(GNL_DIR)
	@echo "All executable files are cleaned!"

re: fclean all

.PHONY: all clean fclean re bonus
