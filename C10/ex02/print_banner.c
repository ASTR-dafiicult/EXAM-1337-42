# include "lib_tail.h"


void print_banner(char *ban)
{
    ft_putstr("==> ");
    ft_putstr(ban);
    ft_putstr(" <==");
    write(1, "\n", 1);           
}