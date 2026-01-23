# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void put_val(int nb)
{
    if(nb == 0)
        return;
    if(nb > 9)
        put_val(nb / 10);

    ft_putchar((nb % 10) + 48);
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        if(*av[1] == 48)
        {
            write(1, "0\n", 2);
            return 0;
        }
        int i = 1;
        while(av[i])
            i++;
        put_val(--i);
    }
    ft_putchar('\n');
}