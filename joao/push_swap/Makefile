# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 20:00:04 by jonascim          #+#    #+#              #
#    Updated: 2023/01/17 07:51:03 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
INCLUDE		= includes
LIBFT		= ../libft
SRC_DIR		= srcs/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I
RM			= rm -f

#Sources

SRC_FILES	=	check_arguments.c first_phase.c first_phase_utils.c get_arguments.c list_utils.c \
				main.c push_op.c quick_sort.c reverse_rotate_op.c rotate_op.c second_phase_utils.c \
				second_phase.c sorting_utils.c swap_op.c

SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))

###

all:		$(NAME)

$(NAME):	$(SRC)
			@make -C $(LIBFT)
			@$(CC) -o $(NAME) $(SRC) -L. $(LIBFT)/libft.a
##-fsanitize=address -static-libsan -g

clean:
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re norm
