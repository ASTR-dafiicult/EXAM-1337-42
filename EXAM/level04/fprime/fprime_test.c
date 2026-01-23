# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_val(int nbr)
{
    if(nbr <= 0)
        return;
    if(nbr > 9)
        print_val(nbr / 10);
    ft_putchar(nbr % 10 + 48);
}
int atoi_ft(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] == 9 || str[i] == 32)
    {
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res;
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nbr = atoi_ft(av[1]);
        int i = 2;
        if(nbr <= 1)
            ft_putchar(nbr + 48);
        while(nbr > 1)
        {
            if(nbr % i == 0)
            {
                print_val(i);
                if(nbr / i > 1)
                    ft_putchar('*');
                nbr /= i;
            }
            else
                i++;
        }
    }
    ft_putchar('\n');
}
