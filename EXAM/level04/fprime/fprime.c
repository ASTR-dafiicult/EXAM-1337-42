# include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] == 32 || str[i] == 9)
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
void print_val(int nb)
{
    if(nb == 0)
        return;
    if(nb > 9)
    {
        print_val(nb / 10);
    }
    ft_putchar(nb % 10 + 48);
}
int check_prime(int nb)
{
    if(nb <= 1)
        return 0;
    int i = 2;
    while(i < nb / 2)
    {
        if(nb % i == 0)
            return (0);

        i++;
    }
    return (1);
}
int next_prime(int index)
{
    index++;
    while(!check_prime(index))
    {
        index++;
    }
    return index;
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nbr = ft_atoi(av[1]);
        int i = 2;
        while(nbr > 1)
        {
            if(nbr % i == 0)
            {
                print_val(i);
                if((nbr / i) > 1)
                    ft_putchar('*');
                nbr /= i;
            }
            else
                i = next_prime(i);
        }
    }
    write(1, "\n", 1);
}