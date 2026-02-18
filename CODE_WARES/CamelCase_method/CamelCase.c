# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <unistd.h>

int space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
char *camel_case(const char *s)
{
    int len = 0;
    while(s[len])
        len++;

    char *tab = calloc((len + 1), sizeof(char));
    if(!tab)   
        return NULL;

    int i = 0;
    int index = 0;
    while(s[i] && i < len)
    {
        while(space(s[i]) && s[i])
            i++;
        if((!space(s[i])) && s[i])
        {
            if(s[i] >= 97 && s[i] <= 122)
                tab[index++] = s[i] - 32;
            else
                tab[index++] = s[i];
            i++;
        }
        while(!space(s[i]) && s[i])
        {
            tab[index++] = s[i++];
        }
    }
    tab[index] = '\0';
    return tab;
}
int main()
{
    const char *str = " camel case word";
    printf("%s\n", camel_case(str));
}