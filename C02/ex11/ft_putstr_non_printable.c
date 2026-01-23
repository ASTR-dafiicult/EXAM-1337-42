# include "stdio.h"
# include "unistd.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putstr_non_printable(char *str)
{
    int i = 0;
    char hex[] = "0123456789abcdef";
    while(str[i])
    {
        if(str[i] >= 7 && str[i] <= 13)
        {
            ft_putchar('/');
            ft_putchar(hex[str[i] / 16]);
            ft_putchar(hex[str[i]]);
        }
        else{
            ft_putchar(str[i]);
        }
        i++;
    }
}
int main()
{
    char str[] = "Coucou\rtu vas bien ?";
    ft_putstr_non_printable(str);
    ft_putchar('\n');
}