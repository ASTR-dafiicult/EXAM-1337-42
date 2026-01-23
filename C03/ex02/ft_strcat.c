



char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    while(dest[i])
    {
        i++;
    }
    int j = 0;
    while(src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
# include "stdio.h"
int main()
{
    char dest[] = "hello";
    char src[] = " world";
    printf("%s\n", ft_strcat(dest, src));
}