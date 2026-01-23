CC = gcc
FLAGS = -Wall -Wextra -Werror 
INCLUDE = -I includes
RM = rm -f
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
PRO = ft_cat

.PHONY: all clean fclean

all:$(PRO)

$(PRO) : $(OBJ)
	@$(CC) $(INCLUDE) $(FLAGS) $(OBJ) -o $@
srcs/%.o: srcs/%.c
	$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean:	clean
	@$(RM) $(PRO)