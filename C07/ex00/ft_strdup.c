# include "unistd.h"
# include "stdlib.h"


char *ft_strdup(char *src)
{
    int i = 0;
    char *str = malloc(sizeof(src));
    while(src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
# include "stdio.h"

int main()
{
    char src[] = "hello world";
    char *str = ft_strdup(src);
    printf("origine : %s\n", src);
    printf("duplicate : %s\n", str);
    free(str);
}