# include "unistd.h"
# include "stdio.h"

int ft_sqrt(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int sqrt = 1;
    while(sqrt < nb)
    {
        if(nb / sqrt == sqrt)
        {
            return sqrt;
        }
        sqrt++;
    }
    return 0;
}
int main()
{
    printf("%d\n", ft_sqrt(25));
}