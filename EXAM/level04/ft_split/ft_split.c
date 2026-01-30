# include <unistd.h>
# include <stdlib.h>


int blank(char c)
{
    if(c == 32 || c == 9 || c == '\0')
    {
        return 0;
    }
    return 1;
}
int counter_string(char *str)
{
    int i = 0;
    int counter = 0;
    while(str[i])
    {
        int val = blank(str[i]);
        if(val)
        {
            if(i == 0 || !blank(str[i - 1]))
            {
                counter++;
            }
        }
        i++;
    }
    return counter;
}
int get_length(char *str)
{
    int length = 0;
    while(blank(str[length]) && str[length])
    {
        length++;
    }
    return length;
}
char *str_cpy(char *str, int length)
{
    char *tab = malloc((length + 1));
    if(!tab)
        return NULL;
    int i = 0;
    while(i < length)
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char    **ft_split(char *str)
{
    int length = counter_string(str);
    int index;
    int size;
    int i;

    char **tab = malloc((length + 1) * sizeof(char *));
    i = 0;
    index = 0;
    size = 0;
    while(str[i])
    {
        if(blank(str[i]))
        {
            size = get_length(&str[i]);
            tab[index] = str_cpy(&str[i], size);
            index++;
            i += size;
        }
        else
        {
            i++;
        }
    }
    tab[index] = NULL;
    return tab;
}
/*
# include <stdio.h>
int main()
{
    char str[] = "the quiter you become. the more you can hear";
    char **tab = ft_split(str);
    int i = 0;
    while(tab[i])
    {
        printf("%s\n", tab[i]);
        i++;
    }
}
*/