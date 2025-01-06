#Name of the program
NAME = ../minishell-lib.a

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Sources
SRC_FT_PRINTF =	ft_print_format.c ft_printf.c \
		ft_putchar_fd_pf.c ft_putendl_fd_pf.c \
		ft_puthex_fd_pf.c ft_puthex_upper_fd_pf.c ft_putnbr_fd_pf.c \
		ft_putptr_fd_pf.c ft_putstr_fd_pf.c ft_putunbr_fd_pf.c \
		ft_utils.c \

SRC = $(wildcard libft/*.c) \
	$(addprefix ft_printf/, $(SRC_FT_PRINTF)) \
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