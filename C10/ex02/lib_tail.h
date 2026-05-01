# ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <errno.h>

void ft_putstr(char *s);
int ft_atoi(char *s);
void ft_tail(char *file, char *program);
void print_banner(char *ban);
void error(void);
void handle_option(char *file, char *program, char *av2, int *valid);

# endif