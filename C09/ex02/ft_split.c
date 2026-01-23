# include <stdio.h>
# include <stdlib.h>

int check_char(char c, char *sep)
{
    int i;
    i = 0;
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
int length_string(char *str, char *charset)
{
    int i;
    int counter;

    i = 0;
    counter = 0;
    while(str[i]) // hel,this
    {
        int val = check_char(str[i], charset);
        if(!val)
        {
            if(i == 0 || check_char(str[i - 1], charset))
            {
                counter++;
            }
        }
        i++;
    }
    return counter;
    
}
int length_every_string(char *str, char *charset)
{
    int i;
    i = 0;
    while(str[i] && !check_char(str[i], charset))
    {
        i++;
    }
    return i;
}
char *copy_string_to_tab(char *str, int length)
{
    char *tab;
    int i;
    tab = malloc(length + 1);
    if(!tab)
    {
        return NULL;
    }
    i = 0;
    while(i < length)
    {
        tab[i] = str[i];
        i++;
    }
    tab[i] = '\0';
    return tab;
}
char **ft_split(char *str, char *charset)
{
    int size;
    int **tab;
    int i;
    int index;
    int length;
    size = length_string(str, charset);
    tab = malloc((size + 1) * sizeof(char *));
    if(!tab)
    {
        return NULL;
    }
    i = 0;
    index = 0;
    length = 0;
    while(str[i])
    {
        if(!check_char(str[i], charset))
        {
            length = length_every_string(&str[i], charset);
            tab[index] = copy_string_to_tab(&str[i], length);
            //goal of this parte of code cleanup all alocation of tab if !tab[index] was NULL
            //that problem name memory leak
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
//إلى خرجنا مباشرة بreturn NULL"
//الميموار لي تخلق قبل غتبقى محجوزة
//هذا اسمو memory leak
int main()
{
    char str[] = ",,hello,this,is,me";
    char charset[] = ",";
    char **res = ft_split(str, charset);
    int i = 0;
    while(res[i])
    {
        printf("%s\n", res[i]);
        i++;
    }
}