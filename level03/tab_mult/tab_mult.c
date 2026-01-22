# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void solve(int nb)
{
    if(nb == 0)
    {
        return;
    }
    if(nb > 9)
    {
        solve(nb / 10);
    }
    ft_putchar((nb % 10) + 48);
}
int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int val = ft_atoi(av[1]);
        if(val <= 0)
        {
            ft_putchar('\n');
            return 0;
        }
        int i = 1;
        int res = 0;
        while(i <= 9)
        {
            res = (i * val);
            solve(i);
            ft_putchar(' ');
            ft_putchar('x');
            ft_putchar(' ');
            solve(val);
            ft_putchar(' ');
            ft_putchar('=');
            ft_putchar(' ');
            solve(res);
            ft_putchar('\n');
            i++;
        }
        return 0;
    }
    write(1, "\n", 1);
}