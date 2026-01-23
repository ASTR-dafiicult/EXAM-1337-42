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
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int src_len = ft_strlen(src);
    unsigned int i = 0;
    while(src[i] && i < size -1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return src_len;
}
int main()
{
    char src[] = "hello";
    char dest[5];
    int size = ft_strlcpy(dest, src, sizeof(dest));
    printf("%d\n", size);
    printf("%s\n", dest);
    if(size >= sizeof(dest))
    {
        printf("tranccation\n");
    }
}
