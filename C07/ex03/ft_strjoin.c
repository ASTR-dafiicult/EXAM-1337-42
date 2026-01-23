# include "stdlib.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int length_srings(int size, char **str, char *sep)
{
    int i = 0;
    int total = 0;
    int len_sep = ft_strlen(sep);
    while(i < size)
    {
        // "hello", "every", "body" | sep = ","
        total += ft_strlen(str[i]);
        if(i < size - 1)
        {
            total += len_sep;
        }
        i++;
    }
    return total;
}
char *ft_strjoin(int size, char **strs, char *sep)
{
    char *tab;
    int total_length = length_srings(size, strs, sep);
    if(size == 0)
    {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }
    tab = malloc(total_length + 1);
    if(tab == NULL)
    {
        return (NULL);
    }
    int i = 0;
    int index = 0;
    int j;
    while(i < size)
    {
        j = 0;
        while(strs[i][j])
        {
            tab[index] = strs[i][j];
            j++;
            index++;
        }
        if(i < size - 1)
        {
            int k = 0;
            while(sep[k])
            {
                tab[index] = sep[k];
                k++;
                index++;
            }
        }
        i++;
    }
    tab[index] = '\0';
    return tab;
}
# include "stdio.h"
int main()
{
    char *str[] = {"hello", "every", "body"};
    char sep[] = ",";
    int size = 3;
    char *string_final = ft_strjoin(size, str, sep);
    printf("%s\n", string_final);
    free(string_final);
}