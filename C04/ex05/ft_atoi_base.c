# include "unistd.h"
# include "stdio.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int is_inbase(char nbr, char *base)
{
    int i = 0;
    while(base[i])
    {
        if(base[i] == nbr)
        {
            return i;
        }
        i++;
    }
    return -1;
}
int handlle_errors(char *base)
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
int ft_atoi_base(char *str, char *base)
{
    int sign = 1;
    int res = 0;
    int i = 0;
    int base_len = ft_strlen(base);
    while(str[i] == 9 || str[i] == 13 || str[i] == 32)
    {
        i++;
    }
    while(str[i])
    {
        if(str[i] == 45 || str[i] == 43)
        {
            if(str[i] == 45)
            {
                sign = -1;
            }
        }
        int val = is_inbase(str[i], base);
        if(val != -1)
        {
            res = res * base_len + val;
        }
        i++;
    }
    return res * sign;
}
int main()
{
    printf("%d\n", ft_atoi_base("0101", "01"));
    printf("Base 10 '12345': %d\n", ft_atoi_base("12345", "0123456789"));
    printf("Base 16 'Affe': %d\n", ft_atoi_base("    --+---+Affe", "0123456789abcdef"));
    printf("Base 16 'ff': %d\n", ft_atoi_base("ff", "0123456789abcdef"));
    printf("Base 2 '10101': %d\n", ft_atoi_base("10101", "01"));
    printf("Base 8 '-10': %d\n", ft_atoi_base("-10", "01234567"));
}