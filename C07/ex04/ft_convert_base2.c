# include "stdio.h"
# include "stdlib.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int check_base(char *base)
{
    int i = 0;
    int j;
    while(base[i])
    {
        j = i + 1;
        while(base[j])
        {
            if(base[i] == base[j])
            {
                return 0;
            }
            j++;
        }
        if(base[i] == 45 || base[i] == 43 || base[i] == 13 || base[i] == 9 || base[i] == 32)
        {
            return 0;
        }
        i++;
    }
    if(i <= 1)
    {
        return 0;
    }
    return 1;
}
int check_in_base(char nbr, char *base)
{
    int i = 0;
    while(base[i])
    {
        if(nbr == base[i])
        {
            return i;
        }
        i++;
    }
    return -1;
}