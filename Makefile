#Name of the program
NAME = ../minishell-lib.a

#Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Sources
LIBFT := ft_atoi.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c \
	ft_isdigit.c ft_itoa.c ft_memset.c \
	ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strcmp.c ft_strcpy.c \
	ft_strdup.c ft_strjoin.c ft_strjoin_all.c \
	ft_strlen.c ft_strncmp.c ft_strncpy.c ft_strstr.c\
	ft_strtrim.c ft_substr.c
LIBFT := $(addprefix libft/, $(LIBFT))

GC := ft_malloc.c ft_cleanup_all.c gc_init.c \
	gc_shutdown.c gc_track.c gc_untrack.c
GC := $(addprefix g_collector/, $(GC))

SRC = $(LIBFT) \
	$(GC) \
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