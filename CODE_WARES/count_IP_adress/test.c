# include <inttypes.h>
# include <unistd.h>


void print(char c)
{
    write(1, &c, 1);
}
void put_nbr(int nb)
{
    if(nb > 9)
        put_nbr(nb / 10);
    print((nb % 10) + 48);
}
int ft_strlen(const char *str)
{
    int i = 0;
    while(str[i] && str[i] != '.')
        i++;
    return i;
}
int ft_atoi(const char *str)
{
    int i = 0;
    int res = 0;
    while(str[i] == 32 || str[i] == 9)
        i++;
    while((str[i] >= '0' && str[i] <= '9') && str[i] != '.')
    {
        res = res * 10 + str[i] - 48;
        i++;
    }
    return res;
}
int power(int nb, int pow)
{
    if(pow == 0)
        return 1;
    nb *= power(nb, pow - 1);

    return nb;
}
uint32_t ips(const char *str)
{
    int a;
    int b;
    int c;
    int d;
    int i = 0;
    int j = 0;
    int len = 0;
    uint32_t result = 0;


    a = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    b = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    c = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    d = ft_atoi(&str[i]);

    result = (uint32_t)((a * power(256, 3)) + (b * power(256, 2)) + (c * 256) + d);
    return result;
}
uint32_t ips_between (const char *start, const char *end)
{
    uint32_t res1 = ips(start);
    uint32_t res2 = ips(end);

    if(res1 > res2)
        return res1 - res2;
    else
        return res2 - res1;
}
int main()
{
    uint32_t res = ips_between("10.0.0.0", "10.0.0.50");
    put_nbr(res);
    print('\n');
}