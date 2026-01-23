# include "stdio.h"


char *ft_strcapitalize(char *str)
{
    int i = 0;
    int first = 1;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z' && first)
        {
            str[i] -= 32;
            first = 0;
        }
        if(str[i] >= '0' && str[i] <= '9')
        {
            first = 0;
        }
        if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')))
        {
            first = 1;
        }
        if(str[i] == 32)
        {
            first = 1;
        }
        i++;
    }
    return str;
}
int main()
{
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
                //Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
    printf("%s\n", ft_strcapitalize(str));
}