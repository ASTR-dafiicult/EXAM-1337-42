# include <unistd.h>
# include <stdio.h>


int check_char(char c, int str_base)
{
    if(c >= 'A' && c <= 'F')
    {
        c += 32;
    }
    char base[] = "0123456789abcdef";
    int i = 0;
    while(base[i])
    {
        if(base[i] == c && i < str_base)
            return i;
        i++;
    }
    return -1;
}
int	ft_atoi_base(const char *str, int str_base)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    if(str_base > 16 || str_base < 2)
    {
        return 0;
    }
    while(str[i] == 32 || str[i] == 9)
        i++;
    while(str[i] == 45 || str[i] == 43)
    {
        if(str[i] == 45)
            sign *= -1;
        i++;
    }
    int val = 0;
    while(str[i])
    {
        val = check_char(str[i], str_base);
        if(val != -1)
        {
            res = res * str_base + val;
        }
        else
            return 0;
        i++;
    }
    return res * sign;
}
int main()
{
    printf("%d\n", ft_atoi_base("101013", 2));
}