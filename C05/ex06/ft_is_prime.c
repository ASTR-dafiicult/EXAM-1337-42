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
int main()
{
    if(!ft_is_prime(5))
    {
        printf("not prime!\n");
    }
    else
        printf("is prime!\n");
}