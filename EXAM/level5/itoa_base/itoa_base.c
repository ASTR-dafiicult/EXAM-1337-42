# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
    if(base > 16 || base < 2)
    {
        return NULL;
    }
    char base_char[] = "0123456789ABCDEF";
    int tmp;
    int size = 0;
    char *str;
    long nb = value;
    
    if(value == 0)
    {
        str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if(nb < 0)
        nb *= -1;
    if(base == 10 && value < 0)
        size = 1;
    tmp = nb;
    while(tmp)
    {
        tmp /= base;
        size++;
    }
    str = malloc(size + 1);
    if(!str)
        return NULL;
    str[size] = '\0';
    if(value < 0 && base == 10)
    {
        str[0] = '-';
    }
    while(nb)
    {
        str[--size] = base_char[nb % base];
        nb /= base;
    }
    return str;
}
int main()
{
    char *str = ft_itoa_base(-2147483647, 10);
    if(str)
    {
        printf("%s\n", str);
        free(str);
    }
    else
        printf("NULL\n");
}