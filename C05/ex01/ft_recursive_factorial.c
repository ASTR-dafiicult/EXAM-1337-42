# include "stdio.h"
# include "unistd.h"


int ft_recursive_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    if(nb <= 1)
    {
        return 1;
    }
    nb *= ft_recursive_factorial(nb - 1);

    return nb;
}
int main()
{
    printf("%d\n", ft_recursive_factorial(5));
}