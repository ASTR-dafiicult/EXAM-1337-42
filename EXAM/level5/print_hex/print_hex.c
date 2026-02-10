# include <unistd.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
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
        int nb = ft_atoi(av[1]);
        int size = 0;
        int i = 0;
        char hex[] = "0123456789abcdef";
        int tmp = nb;
        
        if(nb == 0)
        {
            ft_putchar('0');
            ft_putchar('\n');
            return 0;
        }
        while(tmp)
        {
            tmp /= 16;
            size++;
        }
        char str[size];
        str[size] = '\0';
        i = size - 1;
        while(nb)
        {
            str[i--] = hex[nb % 16];
            nb /= 16;
        }
        i = 0;
        while(str[i])
            ft_putchar(str[i++]);
    }
    ft_putchar('\n');
    return 0;
}