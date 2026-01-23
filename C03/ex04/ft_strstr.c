



char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j;
    while(str[i])
    {
        j = 0;
        while(str[i + j] == to_find[j] && to_find[j])
        {
            j++;
        }
        if(to_find[j] == '\0')
        {
            return &str[i];
        }
        i++;
    }
    return 0;
}
# include "stdio.h"

int main()
{
    char str[] = "hello brother this is me";
    char to_find[] = "ot";
    char *dest = ft_strstr(str, to_find);

    printf("%s\n", dest);
}