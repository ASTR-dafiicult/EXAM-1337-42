#CC = gcc
#FLAGS = -Wall -Wextra -Werror 
#RM = rm -f
#SRC = srcs/main.c
#OBJ = $(SRC:.c=.o)
#BIN_NAME = ft_display_file
#
#.PHONY: all clean fclean
#
#all: $(BIN_NAME)
#
#$(BIN_NAME): $(OBJ)
#	$(CC) $(FLAGS) $(OBJ) -o $@
#clean:
#	@$(RM) $(OBJ)
#fclean:clean
#	@$(RM) $(BIN_NAME)
#	
CC = gcc
FLAGS = -Wall -Wextra -Werror 
RM = rm -f
INCL = -I includes
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)
BIN = ft_display_file

.PHONY: all celan fclean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(INCL) $(FLAGS) $(OBJ) -o $@
srcs/%.o: srcs/%.c
	$(CC) $(INCL) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(BIN)