# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


void swap(char **s1, char **s2)
{
    char *tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
int space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
char convert(char c)
{
    if(c >= 'A' && c <= 'Z')
        return c += 32;
    return c;
}
int count_strings(char *str)
{
    int i = 0;
    int count = 0;
    while(str[i])
    {
        if(!space(str[i]))
        {
            if(i == 0 || space(str[i - 1]))
                count++;
        }
        i++;
    }
    return count;
}
int sort_word_byalpha(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        char cs1 = convert(s1[i]);
        char cs2 = convert(s2[i]);
        if(cs1 != cs2)
            return cs1 - cs2;
        i++;
    }
    return 0;
}
char **ord_alphlong(char *str)
{
    int length = count_strings(str);
    char **word = malloc(sizeof(char *) * (length + 1)); // hello word
    if(!word)
        exit(EXIT_FAILURE);
    int i = 0;
    int index = 0;
    int access = 1;

    while(str[i])
    {
        if(!space(str[i]) && access)
        {
            word[index++] = &str[i];
            access = 0;
        }
        if(space(str[i]))
        {
            str[i] = '\0';
            access = 1;
        }
        i++;
    }
    word[index] = NULL;
    i = 0;
    char *tmp;
    while(word[i])
    {
        int j = i + 1;
        while(word[j])
        {
            if(ft_strlen(word[i]) > ft_strlen(word[j]))
            {
                swap(&word[i], &word[j]);
            }
            if(ft_strlen(word[i]) == ft_strlen(word[j]))
            {
                if(sort_word_byalpha(word[i], word[j]) > 0)
                {
                    swap(&word[i], &word[j]);
                }
            }
            j++;
        }
        i++;
    }
    return word;
}
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}
void print_words(char **word)
{
    int i = 0;
    while(word[i])
    {
        ft_putstr(word[i]);
        if(word[i+1] && ft_strlen(word[i]) == ft_strlen(word[i + 1]))
            write(1, " ", 1);
        else
            write(1, "\n", 1);
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char **res = ord_alphlong(av[1]);
        print_words(res);
        free(res);
    }
    else
        write(1, "\n", 1);
    return 0;
}