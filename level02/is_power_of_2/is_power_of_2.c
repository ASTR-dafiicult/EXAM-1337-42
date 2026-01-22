//# include <unistd.h>


int	    is_power_of_2(unsigned int n)
{
    if(n == 0)
    {
        return 0;
    }
    while((n % 2) == 0)
    {
        n /= 2;
        if(n == 1)
        {
            return 1;
        }
    }
    return 0;
}
/*
# include <stdio.h>
int main()
{
    int n = 4;
    int pow = is_power_of_2(n);
    if(pow)
    {
        printf("%d is power of 2\n", n);
    }
    else
        printf("%d is not power of 2\n", n);
}
*/