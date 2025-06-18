NAME = libft.a

DIR_SRC = .

DIR_OBJ = $(DIR_SRC)/objects

LIBFT_FLAGS = -L $(DIR_LIB) -lft

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c  \
		ft_bzero.c \
		ft_memcpy.c  \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_printf.c \
		ft_printf_chars.c \
		ft_printf_hex.c \

BONUSFILES = 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \

OBJECTS = $(patsubst %.c, $(DIR_OBJ)/%.o, $(notdir $(SOURCES)))

BONUS_OBJECTS = $(BONUSFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $^

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c | $(DIR_OBJ)
	@$(COMPILER) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "compiling $<"

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)
	@echo "Making objects directory"

bonus: .bonus

.bonus: $(C_OBJECTS) $(BONUS_OBJECTS)
	$(AR) $(NAME) $^
	@touch .bonus

clean:
	@$(RM) $(DIR_OBJ)
	@echo "libft objects are removed!"

fclean: clean
	rm -f $(NAME)
	@rm -f .bonus
	@echo "All executable files are removed!"

re: fclean all

.PHONY: all clean fclean re bonus
