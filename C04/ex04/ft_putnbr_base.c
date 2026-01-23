# include "unistd.h"
# include "stdio.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_strlen(char *base)
{
    int i = 0;
    while(base[i])
    {
        i++;
    }
    return i;
}
int handle_error(char *base)
{
    int i = 0;
    int j;
    while(base[i])
    {
        j = i + 1;
        while(base[j])
        {
            if(base[i] == base[j])
            {
                return 0;
            }
            j++;
        }
        if(base[i] == 45 || base[i] == 43)
        {
            return 0;
        }
        i++;
    }
    if(i <= 1)
    {
        return 0;
    }
    return 1;
}
void ft_putnbr_base(int nbr, char *base)
{
    if(!handle_error(base))
    {
        return;
    }
    int base_len = ft_strlen(base);
    int nb = nbr;
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb >= base_len)
    {
        ft_putnbr_base(nb / base_len, base);
    }
    ft_putchar(base[nb % base_len]);
}
int main()
{
    ft_putnbr_base(42, "0123456789");
    ft_putchar('\n'); // decimal base '10'

    ft_putnbr_base(42, "01"); // Binary base "01"
    ft_putchar('\n');

    ft_putnbr_base(42, "0123456789ABCDEF"); // Hexadecimal base
    ft_putchar('\n');

    ft_putnbr_base(-42, "0123456789"); // Negative number
    ft_putchar('\n');

    ft_putnbr_base(42, "poneyvif"); // Should output vn
    ft_putchar('\n');
}