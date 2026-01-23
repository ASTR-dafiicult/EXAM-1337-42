# include "unistd.h"
# include "stdio.h"

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
int main()
{
    char s1[] = "bhmed";
    char s2[] = "aala";

    int res = ft_strcmp(s1, s2);

    printf("%d\n", res);
    if(res > 0)
    {
        printf("kbir\n");
    }
    else{
        printf("sghir\n");
    }
}