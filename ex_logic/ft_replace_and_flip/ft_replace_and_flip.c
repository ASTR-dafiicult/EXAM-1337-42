# include <unistd.h>
# include <stdlib.h>


char *ft_strdup(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    char *RES = malloc((i + 1) * sizeof(char));
    if(!RES)
        exit(EXIT_FAILURE);
    i = 0;
    while(s[i])
    {
        RES[i] = s[i];
        i++;
    }
    RES[i] = '\0';
    return RES;
}
char *ft_itoa(int nb)
{
    int i = 0;
    int tmp = nb;
    while(tmp)
    {
        tmp /= 10;
        i++;
    }
    char *str = malloc((i + 2) * sizeof(char));
    if(!str)
        exit(EXIT_FAILURE);
    str[i + 1] = '\0';
    str[i] = ' ';
    while(nb)
    {
        str[--i] = ((nb % 10) + 48);
        nb /= 10;
    }
    return str;
}
int blank(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
char *convert(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(blank(s1[i]) && blank(s2[i]))
        {
            return 1;
        }
        if(s1[i] != s2[i])
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int coun_words(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        if(!blank(str[i]))
        {
            if(i == 0 || blank(str[i - 1])) //       hello world
                count++;
        }
        i++;
    }
    return count;
}
int length_string(char *str)
{
    int i = 0;
    while(str[i] && !blank(str[i]))
        i++;
    while(str[i] && blank(str[i]))
        i++;
    return i;
}
char *copy(char *str, int length)
{
    char *tab = malloc((length + 1) * sizeof(char));
    if(!tab)
        exit(EXIT_FAILURE);
    int i = 0;
    while(i < length)
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char **new_split(char *str)
{
    int size_w = coun_words(str);
    char **tab = malloc((size_w + 3) * sizeof(char *));
    if(!tab)
        exit(EXIT_FAILURE);

    int i = 0;
    int index = 0;
    int length = 0;
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
    tab[index] = ft_strdup("\n");
    tab[index + 1] = NULL;

    char *conv_5 = NULL;
    i = 0;
    if(size_w > 5)
    {
        char *cop_1 = ft_strdup(tab[1]);
        conv_5 = ft_strdup(tab[5]);
        convert(conv_5);
        while(tab[i])
        {
            if(ft_strcmp(cop_1, tab[i]))
            {
                free(tab[i]);
                tab[i] = ft_strdup(conv_5);
            }
            i++;
        }
        free(tab[5]);
        tab[5] = ft_strdup(cop_1);
        free(conv_5);
        free(cop_1);
    }

    char *size = ft_itoa(size_w + 2);
    int j = size_w + 1;
    j /= 2;
    i = size_w;

    while (i >= j)
    {
        tab[i + 1] = tab[i];
        i--;
    }
    tab[j] = size;
    return tab;
}
char *ft_replace_and_flip(char *str)
{
    char **res = new_split(str);
    int i = 0;
    int j;
    int count = 0;
    while(res[i])
    {
        j = 0;
        while(res[i][j])
        {
            count++;
            j++;
        }
        i++;
    }
    char *tab_final = malloc((count + 1) * sizeof(char));
    if(!tab_final)
        exit(EXIT_FAILURE);

    int in = 0;
    int index = 0;
    while(res[in])
    {
        int k = 0;
        while(res[in][k])
        {
            tab_final[index++] = res[in][k++];
        }
        free(res[in]);
        in++;
    }
    free(res);
    
    tab_final[index] = '\0';
    return tab_final;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char *res = ft_replace_and_flip(av[1]);
        int i = 0;
        while(res[i])
        {
            write(1, &res[i++], 1);
        }
        free(res);
    }
    else
        write(1, "\n", 1);

    exit(EXIT_SUCCESS);
}
//Run   Lo  Lo fast  and 11 go jump Lo here$
//Run   Lo  Lo fast  and 11 go jump Lo here$
