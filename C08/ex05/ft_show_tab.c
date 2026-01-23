# include "ft_str_to_tab.h"
# include <unistd.h>
# include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
char *ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    str[i] = '\0';
    ft_putchar('\n');
    return str;
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb < 10)
    {
        ft_putchar(nb + 48);
    }
    else{
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}
void ft_show_tab(struct s_stock_str *par)
{
    int i = 0;
    while(par[i].str)
    {
        ft_putchar('\n');
        ft_putstr(par[i].str);
        
        ft_putnbr(par[i].size);
        ft_putchar('\n');
        
        ft_putstr(par[i].copy);
        ft_putchar('\n');
        i++;
    }
}
int main(int ac, char **av)
{
    struct s_stock_str *alt;
    alt = ft_strs_to_tab(ac, av);
    ft_show_tab(alt);
}