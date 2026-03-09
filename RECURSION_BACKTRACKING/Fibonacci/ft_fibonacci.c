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
void ft_putnbr(int nb)
{
    long long res = 0;
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);

    ft_putchar((nb % 10) + 48);
}
//long long ft_fibonacci(int nb)
//{
//    long long a = 0;
//    long long b = 1;
//    long long tmp = 0;
//    int i = 0;
//    while(i < nb)
//    {
//        tmp = a + b;
//        a = b;
//        b = tmp;
//        i++;
//    }
//    return b;
//}
int ft_fibonacci(int nb)
{
    if(nb == 1 || nb == 0)
        return nb;
    return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
}
int main(int ac, char **av)
{
    if(ac == 2)
    {        
        int nbr = ft_atoi(av[1]);
        ft_putnbr(ft_fibonacci(nbr));
    }
    write(1, "\n", 1);
}