


int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    while(s1[i] && s2[j])
    {
        if(s1[i] != s2[j])
        {
            return s1[i] - s2[j];
        }
        i++;
        j++;
    }
    return s1[i] - s2[j];
}
# include "stdio.h"
int main()
{
    printf("%d\n", ft_strcmp("hello", "hallo"));
}