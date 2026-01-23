# include "ft_str_to_tab.h"
# include <unistd.h>
# include <stdlib.h>

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
    ft_putchar('\n');
    return str;
}
void ft_putnbr(char nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb *= -1;
    }
    if(nb < 10)
    {
        ft_putchar(nb + 48);
    }
    if(nb > 9)
    {
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

        ft_putchar('\n');
        ft_putstr(par[i].copy);
        
        ft_putnbr(par[i].size);
        ft_putchar('\n');
        i++;
    }
}
# include "stdio.h"
int main(int ac, char **av)
{
    struct s_stock_str *tab;
    tab = ft_strs_to_tab(ac, av);
    ft_show_tab(tab);
 
    char c;
    printf("click 'C' to clear : ");
    scanf("%c", &c);
    if(c == 'C' || c == 'c')
    {
        system("clear");
    }
}