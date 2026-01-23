
int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (s1[i] - s2[i]); // 0 == equal
}
/*
# include <stdio.h>
int main()
{
    char str1[] = "hella";
    char str2[] = "hallo";

    int root = ft_strcmp(str1, str2);
    printf("%d\n", root);
}
*/