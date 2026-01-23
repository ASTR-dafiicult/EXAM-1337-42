# include "stdio.h"
# include "stdlib.h"

int ft_strlen(char *base);
int check_base(char *base);
int check_in_base(char nbr, char *base);


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(!((check_base(base_from)) && (check_base(base_to))))
    {
        printf("error\n");
    }
    int from_len = ft_strlen(base_from);
    int to_len = ft_strlen(base_to);
    int sign = 1;
    int res = 0;
    int i = 0;
    while(nbr[i] == 13 || nbr[i] == 32 || nbr[i] == 9)
    {
        i++;
    }
    while(nbr[i] == 45 || nbr[i] == 43)
    {
        if(nbr[i] == 45)
        {
            sign *= -1;
        }
        i++;
    }
    while(nbr[i])
    {
        int val = check_in_base(nbr[i], base_from);
        if(val != -1)
        {
            res = res * from_len + val;
        }
        else{
            break;
        }
        i++;
    }
    //res   = positive
    //res2  = negative if sign = -1
    //res3  = count digits
    int res2 = res * sign;
    int digits = 0;
    if(res2 < 0)
    {
        digits++;
        res2 = -res;
    }
    int res3 = res;
    while(res3 > 0)
    {
        res3 /= to_len;
        digits++;
    }
    char *str = malloc(digits + 1);
    int index = digits;
    while(res > 0)
    {
        index--;
        str[index] = base_to[res % to_len];
        res /= to_len;
        if(res2 < 0)
        {
            str[0] = '-';
        }
    }
    str[digits] = '\0';
    return str;
}






























int main()
{
    char *res1 = ft_convert_base("-+--FF", "0123456789ABCDEF", "0123456789");
    char *res2 = ft_convert_base("       -+-1011", "01", "0123456789");
    char *res3 = ft_convert_base("30", "0123456789", "0123456789ABCDEF");
    char *res4 = ft_convert_base("-10", "0123456789", "01");
    printf("%s\n", res1);
    printf("%s\n", res2);
    printf("%s\n", res3);
    printf("%s\n", res4);
}