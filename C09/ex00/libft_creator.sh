#!/bin/sh

cd ./srcs
gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
rm -f *.o 