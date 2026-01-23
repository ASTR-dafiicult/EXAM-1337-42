# include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void in_to_out(void)
{
    char c;
    while(read(0, &c, 1))
    {
        ft_putchar(c);
    }
}