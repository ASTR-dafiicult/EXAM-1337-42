//# include <stdlib.h>

/*
int ft_strlen(char *str)
{
        int i = 0;
        while(str[i])
    {
        i++;
    }
    return i;
    }
char    *ft_strdup(char *src)
{
    char *tab;
    int i;
    int src_len = ft_strlen(src);
    tab = malloc((src_len + 1) * sizeof(char *));
    while(src[i])
    {
        tab[i] = src[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
int main()
{
    char *str = "hello";
    char *res = ft_strdup(str);

    printf("%s\n", res);
}
*/
# include <stdlib.h>



char    *ft_strdup(char *src)
{
        int i;
        int size = 0;
        char *tab;
        while(src[size])
                size++;
        tab = (char *)malloc(sizeof(char) * (size + 1));

        if(!tab)
                return NULL;
        i = 0;
        while(src[i])
        {
                tab[i] = src[i];
                i++;
        }
        tab[i] = '\0';
        return tab;
}   
/*
# include <stdio.h>
int main()
{
        char str[] = "hello";
        char *res = ft_strdup(str);
        int i = 0;
        while(res[i])
        {
                printf("%c", res[i]);
                i++;
        }
        printf("%d\n", i);
}
*/