# include "unistd.h"
# include "stdio.h"


int ft_atoi(char *str)
{
    int sign = 1;
    int res = 0;
    int i = 0;
    while(str[i])
    {
        if(str[i] == 13 || str[i] == 9 || str[i] == 32)
        {
            i++;
        }
        if(str[i] == 45 || str[i] == 43)
        {
            if(str[i] == 45)
            {
                sign = -1;
            }
        }
        if(str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - 48;
        }
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            return res * sign;
        }
        i++;
    }
    return res * sign;
}
int main()
{
    printf("%d\n", ft_atoi("        --+---+1234abcDEF"));
}