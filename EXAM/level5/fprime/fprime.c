# include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print(int nb)
{
    if(nb == 0)
        ft_putchar('0');
        return;
    if(nb > 9)
        print(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        long nb = ft_atoi(av[1]);
        int i = 2;
        while(nb > 1)
        {
            if(nb % i == 0)
            {
                print(i);
                nb /= i;
                if(nb > 1)
                    ft_putchar('*');
            }
            else{
                i++;
            }
        }
    }
    ft_putchar('\n');
    return 0;
}