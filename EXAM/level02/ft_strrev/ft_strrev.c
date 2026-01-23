# include <unistd.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
char    *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    char val;
    str[len] = '\0';
    while(i < --len)
    {
        val = str[i];
        str[i] = str[len];
        str[len] = val;

        i++;
    }
    return str;
}
/*
# include <stdio.h>
int main()
{
    char str[] = "never more";
    char *res = ft_strrev(str);
    printf("%s\n", res);
}
*/
