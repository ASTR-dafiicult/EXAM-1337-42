# include <unistd.h>
# include <stdio.h>


int ft_atoi(char *str)
{
    int res = 0;
    int i = 0;
    int sign = 1;
    while(str[i] == 32 || str[i] == 9 || str[i] == 13)
    {
        i++;
    }
    while(str[i] == 43 || str[i] == 45)
    {
        if(str[i] == 45)
        {
            sign = -1;
        }
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {    
        res = res * 10 + str[i] - 48;
        i++;
    }
    return (res * sign);
}
int check_op(char op)
{
    if(op == 47 || op == 43 || op == 42 || op == 45 || op == 37)
    {
        return op;
    }
    return 0;
}