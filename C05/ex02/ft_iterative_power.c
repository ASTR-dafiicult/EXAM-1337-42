# include "unistd.h"
# include "stdio.h"


int ft_iterative_power(int nb, int power)
{
    if(power == 0)
    {
        return 1;
    }
    if(power < 0)
    {
        return 0;
    }
    int i = 1;
    int nbr = nb;
    while(i < power)
    {
        nb = nb * nbr;
        i++;
    }
    return nb;
}
int main()
{
    printf("%d\n", ft_iterative_power(5, 4));
}