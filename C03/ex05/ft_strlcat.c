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
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int dest_len = ft_strlen(dest);
    int src_len = ft_strlen(src);

    int i = 0;
    int j = dest_len;
    while(src[i] && j < size - 1)
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    if(size <= dest_len)
    {
        return src_len + size;
    }
    return dest_len + src_len;
}
int main()
{
    char dest[20] = "hello ";
    char src[] = "world";
    int res = ft_strlcat(dest, src, 4);

    printf("%s | %d\n", dest, res);
}