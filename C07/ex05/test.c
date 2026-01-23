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
// admin,,hello,boy
int count(char *str, char *sep)
{
    int i = 0;
    int cunt = 0;
    while(str[i])
    {
        int val1 = check_char(str[i], sep);
        if(!val1 && (i == 0 || check_char(str[i - 1], sep)))
        {
            cunt++;
        }
        i++;
    }
    return cunt;
}
int length_word(char *str, char *sep)
{
    int i = 0;
    while(str[i] && !check_char(str[i], sep))
    {
        i++;
    }
    return i;
}
char *copy_word(char *str, int len)
{
    int i = 0;
    char *word = malloc(len + 1);
    while(i < len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}
char **ft_split(char *str, char *charset)
{
    int size = count(str, charset);
    int i = 0;
    int index = 0;
    int length;
    char **tab = malloc(size + 1 * sizeof(char *));

    while(str[i])
    {
        if(!check_char(str[i], charset))
        {
            length = length_word(&str[i], charset);
            tab[index] = copy_word(&str[i], length);
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
    char str[] = ",,admin,,,hello,boy";
    char sep[] = ",";
    char **counter = ft_split(str, sep);
    int i = 0;
    while(counter[i])
    {
        printf("%s\n", counter[i]);
        i++;
    }
    printf("\n");
}
