# include <unistd.h>
# include <stdlib.h>



int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;

    return i;
}
char *str_add_remove(char **str, char *s, int len)
{
    char *result = malloc((len + 1) * sizeof(char));
    int i = 0;
    int j;
    int index = 0;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if(index == 0)
            {
                result[index++] = s[0];
            }
            result[index++] = str[i][j++];
        }
        i++;
        if(str[i] == NULL)
        {
            result[index++] = s[len - 1];
        }
    }
    result[index] = '\0';
    return result;
}
char *str_add(char **str, int len)
{
    char *res = malloc((len + 1) * sizeof(char));
    
    int i = 0;
    int index = 0;
    int j;
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            res[index++] = str[i][j++];
        }
        i++;
    }
    res[index] = '\0';
    return res;

}
void swap(char **s1, char **s2)
{
    char *tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
char *remove_ele(char *str, int len)
{
    if(str[1] == '0')
    {
        char *tab = malloc((len + 1) * sizeof(char));
        int i = 0;
        while(str[i])
        {
            tab[i++] = str[i++];
        }
        tab[i] = '\0';
        return tab;
    }
    char *tab = malloc((len - 2 + 1) * sizeof(char));
    if(!tab)
        exit(EXIT_FAILURE);

    int i = 1;
    int j = 0;
    while(str[i] && i < len - 1)
    {
        tab[j++] = str[i++];
    }
    tab[j] = '\0';
    return tab;
}
char *copy(char *str, int from, int to)
{
    char *tab = malloc((to - from + 1) * sizeof(char));
    if(!tab)
    exit(EXIT_FAILURE);
    int i = 0;
    while(str[from] && from < to)
    {
        tab[i++] = str[from++];
    }
    tab[i] = '\0';
    return tab;
}
char* makeLargestSpecial(char* s) 
{
    int len_s = ft_strlen(s);
    
    if(len_s <= 5)
    {
        return s;
    }
    char **str = malloc((10) * sizeof(char *));
    if(!str)
        exit(EXIT_FAILURE);
    char *res = remove_ele(s, len_s);
    
    int res_len = ft_strlen(res);
    if(res_len <= 5)
    {
        free(str);
        free(res);
        return s;
    }
    int i = 0;
    int j = 0;
    int index = 0;
    int counter = 0;
    while(res[i])
    {
        if(res[i] == '1')
            counter++;
        else
            counter--;
        
        if(counter == 0)
        {
            str[index++] = copy(res, j, i + 1);
            j = i + 1;
        }
        i++;
    } 
    str[index] = NULL;

    i = 0;
    j;
    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if(ft_strcmp(str[i], str[j]) < 0)
                swap(&str[i], &str[j]);
            j++;
        }
        i++;
    }

    if(!ft_strcmp(res, s))
    {
        char *tab = str_add(str, len_s);
        int k = 0;
        while(str[k])
            free(str[k++]);
        free(str);
        free(res);
        return tab;
    }
    else
    {
        char *tab = str_add_remove(str, s, len_s);
        int k = 0;
        while(str[k])
            free(str[k++]);
        free(str);
        free(res);
        return tab;
    }
}
/*
# include <stdio.h>
int main()
{
    char s1[] = "11011000";
    char s2[] = "10";
    char s3[] = "11100010";
    char s4[] = "1010101100";

    char *res = makeLargestSpecial(s3);
    printf("%s\n", res);
    free(res);
    
}
*/