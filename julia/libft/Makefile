# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 18:42:50 by ipersids          #+#    #+#              #
#    Updated: 2025/04/22 13:54:20 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Platform-specific settings
ifeq ($(OS),Windows_NT)
    RM = del /q
    RM_DIR = rmdir /s /q
    LIB_EXT = .lib
else
    RM = rm -f
    RM_DIR = rm -rf
    LIB_EXT = .a
endif

# Library file
NAME		:= libft$(LIB_EXT)

# Compilation variables
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
HDRS		= -Iinclude
AR 			= ar
ARFLAGS 	= -rcs

# Files
SRCS		:= src/char/ft_isalnum.c src/char/ft_isalpha.c src/char/ft_isascii.c \
			   src/char/ft_isdigit.c src/char/ft_isprint.c src/char/ft_isspace.c \
			   src/char/ft_tolower.c src/char/ft_toupper.c \
			   src/get-next-line/get_next_line.c \
			   \
			   src/ft-printf/ft_printf.c src/ft-printf/ft_putchar_fd.c \
			   src/ft-printf/ft_puthex_fd.c src/ft-printf/ft_puthex_fd.c \
			   src/ft-printf/ft_putnbr_fd.c src/ft-printf/ft_putptr_fd.c \
			   src/ft-printf/ft_putstr_fd.c src/ft-printf/ft_putunmb_fd.c \
			   \
			   src/mem-allocation/ft_calloc.c src/mem-allocation/ft_realloc.c \
			   \
			   src/memory/ft_memchr.c src/memory/ft_memcmp.c src/memory/ft_memcpy.c \
			   src/memory/ft_memmove.c src/memory/ft_memset.c \
			   \
			   src/number/ft_atoi.c src/number/ft_itoa.c src/number/ft_atol.c \
			   src/number/ft_strtod.c \
			   \
			   src/string/ft_split.c src/string/ft_strchr.c src/string/ft_strdup.c \
			   src/string/ft_strjoin.c src/string/ft_strlcat.c src/string/ft_strlcpy.c \
			   src/string/ft_strlen.c src/string/ft_strncmp.c src/string/ft_strnstr.c \
			   src/string/ft_strrchr.c src/string/ft_strtrim.c src/string/ft_substr.c \
			   src/string/ft_strcmp.c \
			   \
			   src/math/ft_max.c src/math/ft_min.c src/math/ft_rand.c \
			   src/math/ft_abc.c src/math/ft_binary_exponentiation.c
			   
OBJS		:= $(SRCS:%.c=%.o)

# Targets
all: $(NAME)

# Create the static library
$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)
	@echo "\n\033[1;30;42mLibrary $(NAME) created.\033[0m\n"

# Compile source files into object files
%.o: %.c
	@$(CC) $(CFLAGS) $(HDRS) -c $< -o $@
	@echo "Compiled\t \033[036m$@\033[0m using $(CC) compiler and $(CFLAGS) flags."

# Clean up object files
clean:
	@$(RM) -f $(OBJS)
	@echo "Cleaned the object files."

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Cleaned the executable file."

# Clean up object files and their directory
re: fclean all
	@echo "\nCleaning and rebuilding process completed.\n"

# Phony targets
.PHONY: all clean re bonus fclean