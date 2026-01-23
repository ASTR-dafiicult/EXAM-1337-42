CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
INCLUDE = -I includes
SRC = $(FILES)
OBJ = $(FILES:.c=.o)
AR = ar rcs
RM = rm -f
LIB = libft.a

.PHONY:all clean fclean re

all: $(LIB)

$(LIB) : $(OBJ)
	$(AR) $(LIB) $(OBJ)
%.o:%.c
	$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB)

re: fclean all
