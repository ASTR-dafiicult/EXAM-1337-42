# include <unistd.h>
# include <stdio.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int sum_positive(int nb)
{
    int sum = 0;
    if(nb == 0)
        return 0;
        
    if(nb % 2 == 0)
        return nb += sum_positive(nb - 1);
    else
        sum_positive(nb - 1);
}
int main()
{
    int nb = 10;
    ft_putnbr(sum_positive(nb));
    ft_putchar('\n');
}
