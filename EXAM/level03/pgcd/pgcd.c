# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void put_val(int res)
{
    if(res == 0)
        return;
    if(res > 9)
    {
        put_val(res / 10);
    }   
    ft_putchar(res % 10 + 48);
}
int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while(str[i] == 13 || str[i] == 9)
    {
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * sign;
}
int pgcd(int val1, int val2)
{
    int rem = 0;
    while((rem = val1 % val2) != 0)
    {
        val1 = val2;
        val2 = rem;
    }
    return val2;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int result = 0;
        int val1 = ft_atoi(av[1]);
        int val2 = ft_atoi(av[2]);
        if(val1 < 0 || val2 < 0)
        {
            write(1, "\n", 1);
            return 0;
        }
        put_val(pgcd(val1, val2));
    }
    write(1, "\n", 1);
}
