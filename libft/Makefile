# Name of the library
NAME = ../libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# List of source files
SRC := ft_atoi.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c \
	ft_isdigit.c ft_itoa.c ft_memset.c \
	ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strcmp.c ft_strcpy.c \
	ft_strdup.c ft_strjoin.c ft_strjoin_all.c \
	ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strstr.c\
	ft_strtrim.c ft_substr.c
SRC := $(addprefix libft/, $(SRC))

# Object files (by replacing .c with .o)
OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
	@$(AR) rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."

# Rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< into $@."

# Clean the object files
clean:
	@rm -f $(OBJ)
	@echo "Object files cleaned."

# Clean everything including the library
fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

# Recompile everything
re: fclean all


.PHONY: all clean fclean re