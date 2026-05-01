CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC := main.c error.c ft_tail.c ft_atoi.c ft_putstr.c option_c.c print_banner.c
OBJ := $(SRC:.c=.o)
RM = rm -f
NAME = ft_tail


.PHONY: all clean fclean re

all:$(NAME)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) -g $(FLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re:fclean all
