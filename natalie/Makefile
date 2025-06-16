# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmeintje <nmeintje@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 09:44:56 by nmeintje          #+#    #+#              #
#    Updated: 2024/08/14 10:44:32 by nmeintje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	./push_swap.c \
		./sorting_functions.c \
		./process_arguments.c \
		./operations_push_swap.c \
		./operations_rotate.c \
		./operations_rev_rotate.c \
		./check_charac.c \
		./free_and_error.c \
		./ft_split.c \
		./list_functions.c \
		./assign_indices.c \
		./helper_functions.c \
		./list_utils.c \
		./populate_stack_b.c \
		./populate_stack_a.c \

OBJS = $(SRCS:.c=.o)

HEAD = push_swap.h 

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -r

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re

