# ifndef LIBCAT_H
# define LIBCAT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

void ft_cat(char *program, char *filename);
void ft_putstr(char *str);
void in_to_out(void);

# endif