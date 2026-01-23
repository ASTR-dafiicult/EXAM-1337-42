# include <unistd.h>


int	ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while(str[i] == 13 || str[i] == 9 || str[i] == 32)
    {
        i++;
    }
    if(str[i] == 45 || str[i] == 43)
    {
        if(str[i] == 45)
        {
            sign *= -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res * sign;
}
/*
# include "stdio.h"
int main()
{
    const char str[] = "   +12345abcfdr";
    int res = ft_atoi(str);
    printf("%d\n", res);
}
*/