#Name of the program
NAME = ../minishell-lib.a

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Sources
SRC = $(wildcard libft/*.c) \
	$(wildcard collector/*.c) \
	get_next_line.c

#Rules
all: $(NAME)

#Objects
OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

#Default rule
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@rm -f $(EXE_FILE)

fclean: clean
	@rm -f *.a

re: fclean all

.PHONY: all clean fclean re