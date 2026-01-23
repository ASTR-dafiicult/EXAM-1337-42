# include "stdio.h"
# include "stdlib.h"


int ft_strlen(char *base);
int check_base(char *base);
int check_in_base(char nbr, char *base);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(!((check_base(base_from)) && (check_base(base_to))))
    {
        return (NULL);
    }
    int len_from = ft_strlen(base_from);
    int len_to = ft_strlen(base_to);
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
            res = res * len_from + val;
        }
        else{
            break;
        }
        i++;
    }
    int res2 = res * sign; // 'res2' may contain a negative result
    int res3 = res; // used to count the number of digits without modifying the original 'res'
    int digits = 0;
    if(res2 < 0) // we use 'res2' to check whether it contains '-' and increase the digit count by 1
    {
        digits++;
        res2 = -res;
    }
    while(res3 > 0)// use res3 to count digits (res3 = res)
    {
        res3 /= len_to;
        digits++;
    }
    int index = digits;
    char tab[index];
    while(index > 0)// fill tab from 'base_to'
    {
        index--;
        tab[index] = base_to[res % len_to];
        res /= len_to;
        if(res2 < 0)// add '-' to start if 'res2 < 0'
        {
            tab[0] = '-';
        }
    }
    char *str = malloc(digits + 1);
    int k = 0;
    while(k < digits) // fill str
    {
        str[k] = tab[k];
        k++;
    }
    str[k] = '\0';
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
    free(res1);
    free(res2);
    free(res3);
    free(res4);
}