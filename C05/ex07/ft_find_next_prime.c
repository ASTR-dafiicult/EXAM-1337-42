# include "unistd.h"
# include "stdio.h"

int ft_is_prime(int nb)
{
    if(nb <= 1)
    {
        return 0;
    }
    int i = 2;
    while(i <= nb / 2)
    {
        if(nb % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int ft_find_next_prime(int nb)
{
    while(!ft_is_prime(nb))
    {
        nb++;
    }
    return nb;
}
int main()
{
    printf("%d\n", ft_find_next_prime(0));
}