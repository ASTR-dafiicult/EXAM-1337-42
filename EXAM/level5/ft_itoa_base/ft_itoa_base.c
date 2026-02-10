# include <unistd.h>
# include <stdlib.h>


char	*ft_itoa_base(int value, int base)
{
    if(base > 16 || base < 2)
        return NULL;
    
    int size;
    int i;
    int nb;
    int tmp;
    char base_char[] = "0123456789ABCDEF";
    char *str;

    nb = value;
    size = 0;
    if(value < 0 && base == 10)// handel "-" for base10
        size = 1;
    if(nb < 0)
        nb *= -1;
    
    tmp = nb;
    while(tmp)
    {
        tmp /= base;
        size++;
    }
    
    str = malloc(size + 1);
    if(!str)
        return NULL;
    
    if(value == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    str[size] = '\0';
    i = size - 1;
    if(value < 0 && base == 10)
    {
        str[0] = '-';
        value = nb;
    }
    while(nb)
    {
        str[i--] = base_char[nb % base];
        nb /= base;
    }
    return str;
}
/*
# include <stdio.h>
int main()
{
    char *str = ft_itoa_base(123143, 16);
    int i = 0;
    if(str)
    {
        printf("%s\n", str);
        free(str);
    }
    else
    printf("NULL\n");
}
*/