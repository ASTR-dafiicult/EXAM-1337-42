# include "unistd.h"
# include "stdio.h"

int ft_recursive_power(int nb, int power)
{
    if(power == 0 && nb == 0)
    {
        return 1;
    }
    if(power < 0)
    {
        return 0;
    }
    if(power == 1)
    {
        return nb;
    }
    nb *= ft_recursive_power(nb , power - 1);
    return nb;
}
int main()
{
    printf("%d\n", ft_recursive_power(6, 4));
}