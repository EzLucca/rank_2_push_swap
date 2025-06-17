# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hutzig <hutzig@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 12:04:49 by hutzig            #+#    #+#              #
#    Updated: 2024/08/30 18:27:25 by hutzig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_LIBFT = ./lib/libft
DIR_SRC = ./sources
DIR_OBJ = $(DIR_SRC)/objects

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L $(DIR_LIBFT) -lft

SOURCES = push_swap.c \
	data_processing.c \
	error_checking.c \
	error_handling.c \
	execute_operations.c \
	operations_push.c \
	operations_reverse.c \
	operations_rotate.c \
	operations_swap.c \
	pushing_a_to_b.c \
	pushing_b_to_a.c \
	stack_sorting.c \
	stack_utils.c \

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))

OBJECTS = $(patsubst %.c,$(DIR_OBJ)/%.o,$(notdir $(SOURCES)))

HEADERS = -I ./includes -I $(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)/libft.a

RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(DIR_LIBFT)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBFT_FLAGS) $(HEADERS) -o $@
	@echo "push_swap program is generated!"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "Compiling: $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

clean:
	@$(RM) $(DIR_OBJ)
	@make clean -C $(DIR_LIBFT)
	@echo "push_swap objects are removed!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(DIR_LIBFT)
	@echo "All executable files are removed!"

re: fclean all

.PHONY: all clean fclean re
