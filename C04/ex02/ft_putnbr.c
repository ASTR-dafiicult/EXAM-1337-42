# include "unistd.h"
# include "stdio.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nbr)
{
    if(nbr == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
        return;
    }
    if(nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if(nbr >= 10)
    {
        ft_putnbr(nbr / 10);
    }
    ft_putchar(nbr % 10 + 48);
}
int main()
{
    ft_putnbr(-348);
    ft_putchar('\n');
}