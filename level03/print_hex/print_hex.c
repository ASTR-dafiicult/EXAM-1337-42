# include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while(str[i] == 32 || str[i] == 9)
    {
        i++;
    }
    while(str[i] == 45 || str[i] == 43)
    {
        if(str[i] == 45)
        {
            sign *= -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * sign;
}
void print_hex(unsigned int nb)
{
    char hex[] = "0123456789abcdef";
    char tab[16];
    int i = 0;
    while(nb)
    {
        tab[i] = hex[nb % 16];
        nb /= 16;
        i++;
    }
    while(i >= 0)
    {
        ft_putchar(tab[i]);
        i--;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int val1 = ft_atoi(av[1]);
        if(val1 < 0)
        {
            write(1, "\n", 1);
            return 0;
        }
        print_hex(val1);
    }
    write(1, "\n", 1);
}