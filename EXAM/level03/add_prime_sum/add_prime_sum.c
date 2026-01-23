# include <unistd.h>
# include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void putval(int nb)
{
    if(nb == 0)
        return;
    if(nb > 9)
    {
        putval(nb / 10);
    }
    ft_putchar((nb % 10) + 48);
}
int check_prime(int nb)
{
    if(nb <= 1)
    {
        return 0;
    }
    int i = 2;
    int sum = 0;
    while(i <= nb / 2)
    {
        if(nb % i == 0)
        {
            return 0;
        }
        i++;
    }
    return nb;
}
int ft_atoi_ft(char *s1)
{
    int i = 0;
    int res = 0;
    while(s1[i] >= '0' && s1[i] <= '9')
    {
        res = res * 10 + s1[i] - 48;
        i++;
    }
    return res;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 2;
        int val = 0;
        int sum = 0;
        
        val = ft_atoi_ft(av[1]);
        while(i <= val)
        {
            if(check_prime(i))
            {
                sum += i;
            }
            i++;
        }
        putval(sum);
    }
    else{
        ft_putchar('0');
        ft_putchar('\n');
        return 0;
    }
    ft_putchar('\n');
}