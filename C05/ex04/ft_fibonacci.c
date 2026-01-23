# include "unistd.h"
# include "stdio.h"


int ft_fibonacci(int index)
{
    if(index == 0)
    {
        return 0;
    }
    if(index == 1)
    {
        return 1;
    }
    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}
int main()
{
    int term = 10;
    int index = 0;
    while(index <= term)
    {
        printf("%d  ", ft_fibonacci(index));
        index++;
    }
    printf("\n");
}