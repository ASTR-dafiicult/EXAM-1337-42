# include "stdio.h"
# include "stdlib.h"

int check_char(char c, char *sep)
{
    int i = 0;
    while(sep[i])
    {
        if(c == sep[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int count_strings(char *str, char *sep)
{
    int i = 0;
    int counter = 0;
    while(str[i])
    {
        int val = check_char(str[i], sep);
        if(!val)
        {
            if(i == 0 || check_char(str[i - 1], sep))
            {
                counter++;
            }
        }
        i++;
    }
    return counter;
}
int length_every_string(char *str, char *sep)
{
    int i = 0;
    while(str[i] && !check_char(str[i], sep))
    {
        i++;
    }
    return i;
}
char *malloc_copy(char *str, int length)
{
    int i = 0;
    char *word = malloc(length + 1);
    if(!word)
    {
        return NULL;
    }
    while(i < length)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}
char **ft_split(char *str, char *charset)
{
    int size = count_strings(str, charset);
    char **tab = malloc((size + 1) * sizeof(char *));
    int index = 0;
    int i = 0;
    int length;
    while(str[i])
    {
        
        if(!check_char(str[i], charset))
        {
            length = length_every_string(&str[i], charset);
            tab[index] = malloc_copy(&str[i], length);
            if(!tab[index])
            {
                int j = 0;
                while(j < size)
                {
                    free(tab[j]);
                    j++;
                }
                free(tab);
                return NULL;
            }
            index++;
            i += length;
        }
        else{
            i++;
        }
    }

    tab[index] = NULL;
    return tab;
}
int main()
{
    char str[] = ",,hello,,,admin,core,";
    char sep[] = ",";
    char **res = ft_split(str, sep);
    int i = 0;
    while(res[i])
    {
        printf("%s\n", res[i]);
        i++;
    }
    free(res);
}