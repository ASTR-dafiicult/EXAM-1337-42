


int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i = 0;
    while(s1[i] && s2[i] && i < n)
    {
        if(s1[i] != s2[i])
        {
            return (unsigned)s1[i] - (unsigned)s2[i];
        }
        i++;
    }
    return 0;
}
# include "stdio.h"
int main()
{
    printf("%d\n", ft_strncmp("ABCD" , "ABAD", 3)); // 2
}