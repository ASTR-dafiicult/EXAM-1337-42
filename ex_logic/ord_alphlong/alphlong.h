# include <stdlib.h>
# include <unistd.h>

int blank(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
int to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}
void swap(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int sort_length(char *s1, char *s2)
{
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    if(len1 > len2)
        return 1;
    return 0;
}
int count_word(char *str)
{
    int i = 0;
    int counter = 0;
    while(str[i])
    {
        if(!blank(str[i]))
        {
            if(i == 0 || blank(str[i - 1]))
                counter++;
        }
        i++;
    }
    return counter;
}
int length_string(char *str)
{
    int i = 0;
    while(str[i] && !blank(str[i]))
        i++;

    return i;
}
char *copy(char *str, int length)
{
    int i = 0;
    char *tab = calloc(length + 1, sizeof(char));
    if(!tab)
    return NULL;
    while(i < length)
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char **split(char *str)
{
    int size = count_word(str);
    char **tab = malloc((size + 1) * sizeof(char *));
    if(!tab)
        return NULL;
    int i = 0;
    int index = 0;
    int length;
    while(str[i])
    {
        if(!blank(str[i]))
        {
            length = length_string(&str[i]);
            tab[index++] = copy(&str[i], length);
            i += length;
        }
        else
        i++;
    }
    tab[index] = NULL;
    return tab;
}
int ord_alphlong(char *s1 , char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(to_lower(s1[i]) != to_lower(s2[i]))
            return (to_lower(s1[i]) - to_lower(s2[i]));
        i++;
    }
    return to_lower(s1[i]) - to_lower(s2[i]);
}
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}