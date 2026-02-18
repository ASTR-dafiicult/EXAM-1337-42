#include <stdlib.h>
# include <stdio.h>
# include <string.h>

void swap(char **a, char **b)
{
    char *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
int weight(char *s)
{
    int sum = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i] >= '0' && s[i] <= '9')
            sum += s[i] - '0';
        i++;
    }
    return sum;
}
int compare(char *a, char *b)
{
    int wa = weight(a);
    int wb = weight(b);

    if (wa < wb)
        return -1;
    if (wa > wb)
        return 1;
    return strcmp(a, b);
}
int space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
int count_words(const char *str)
{
    int count = 0;
    int i = 0;
    while(str[i])
    {
        if(!space(str[i]))
        {
            if(i == 0 || space(str[i - 1]))
            {
                count++;
            }
        }
        i++;
    }
    return count;
}
int length_word(const char *word)
{
    int i = 0;
    while(word[i] && !space(word[i]))
    {
        i++;
    }
    return i;
}
char *copy(const char *word, int length)
{
    int i = 0;
    char *str = malloc((length + 1) * sizeof(char));
    if(!str)
        return NULL;
    while(i < length)
    {
        str[i] = word[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
char *orderWeight(const char *string)
{
    int len = 0;
    while(string[len])
        len++;   

    int size = count_words(string);
    char **str = malloc((size + 1) * sizeof(char*));
    int i = 0;
    int index = 0;
    while(string[i])
    {
        if(!space(string[i]))
        {
            int length = length_word(&string[i]);
            str[index] = copy(&string[i], length);
            index++;
            i += length;
        }
        else
            i++;
    }
    str[index] = NULL;

    i = 0;
    int k;
    while (str[i])
    {
        k = i + 1;
        while (str[k])
        {
            if (compare(str[i], str[k]) > 0)
                swap(&str[i], &str[k]);
            k++;
        }
        i++;
    }
    i = 0;
    int j;
    index = 0;
    char *tab = malloc((len + 1) * sizeof(char));
    while(str[i])
    {
        j = 0;
        while(str[i][j])
        {
            tab[index++] = str[i][j];
            j++;
        }
        i++;
        if(str[i] != NULL)
        {
            tab[index++] = ' ';
        }
    }
    tab[index] = '\0';
    return tab;
}
int main()
{
    char str[] = "103 123 4444 99 2000";
    char *tab = orderWeight(str);
    int i = 0;
    while(tab[i])
    {
        printf("%c", tab[i]);
        i++;
    }
    printf("\n");
}