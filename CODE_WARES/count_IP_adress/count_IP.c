# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

int ft_strlen(const char *str)
{
    int length = 0;
    while(str[length] && str[length] != '.')
        length++;

    return length;
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
uint32_t convert_string(const char *str)
{
    int len;
    int i = 0;

    int a = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    int b = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    int c = ft_atoi(&str[i]);
    len = ft_strlen(&str[i]);
    i += (len + 1);
    int d = ft_atoi(&str[i]);

    uint32_t res = (uint32_t)((a * pow(256, 3)) + (b * pow(256, 2)) + (c * 256) + d);

    return res;
}
uint32_t ips_between (const char *start, const char *end)
{
    uint32_t result1 = 0;
    uint32_t result2 = 0;

    result1 = convert_string(start);
    result2 = convert_string(end);
    if(result1 > result2)
        return result1 - result2;
    else
        return result2 - result1;
}
int main()
{
    const char *ip = "20.0.0.10";
    const char *ip2 = "20.0.1.0";

    uint32_t res = ips_between(ip, ip2);
    printf("%d\n", (int)res);
}