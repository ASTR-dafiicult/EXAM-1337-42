
# include <unistd.h>
# include <stdlib.h>

int check_base(char c, char *base)
{
    if(c >= 'A' && c <= 'F')
    {
        c += 32;
    }
    int i = 0;
    while(base[i])
    {
        if(c == base[i])
        {
            return i;
        }
        i++;
    }
    return -1;
}
int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int res = 0;
    int val = 0;
    int sign = 1;
    char full_bases[] = "0123456789abcdef";
    
    if(str_base > 16 || str_base < 2)
    {
        return 0;
    }
    while(str[i] == 32 || str[i] == 9)
    {
        i++;
    }
    while(str[i] == 45 || str[i] == 43)
    {
        if(str[i] == 45)
        {
            sign *= -1;
        }
        i++;
    }
    while(str[i])
    {
        val = check_base(str[i], full_bases);
        if(val != -1)
        {
            res = res * str_base + val;
        }
        else
            return 0;
        i++;
    }
    return (res * sign);
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int val = ft_atoi_base(av[1], atoi(av[2]));
        printf("value : %d\n", val);
    }
    write(1, "\n", 1);
}
