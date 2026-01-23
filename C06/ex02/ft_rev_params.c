# include "unistd.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int main(int ac, char **av)
{
    int i = 1;
    int j;
    while(i < ac)
    {
        j = 0;
        while(av[ac - 1][j])
        {
            ft_putchar(av[ac - 1][j]);
            j++;
        }
        ft_putchar('\n');
        ac--;
    }
    return 0;
}