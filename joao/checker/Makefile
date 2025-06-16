# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 10:58:59 by jonascim          #+#    #+#              #
#    Updated: 2023/01/17 13:25:18 by jonascim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker
INCLUDE		= includes
LIBFT		= ../libft
SRC_DIR		= srcs/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I
RM			= rm -f

#Sources

SRC_FILES	=	c_check_arguments.c checker_main.c c_get_arguments.c list_utils.c quick_sort.c\
				get_next_line_ps.c  reverse_rotate_op.c push_op.c rotate_op.c swap_op.c

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
