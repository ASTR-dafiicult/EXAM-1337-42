# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char convert(char c)
{
    if(c >= 97 && c <= 122)
    {
        c -= 32;
        return c;
    }
    if(c >= 65 && c <= 90)
    {
        c += 32;
        return c;
    }
        return 0;
}
int check_char(char c, char *str)
{
    int i = 0;
    while(str[i])
    {
        if(c == str[i] || convert(c) == str[i])
            return 0;
        i++;
    }
    return 1;
}
size_t duplicate_count(const char *text)
{
    int len = 0;
    while(text[len])
        len++;
    char *str = malloc((len + 1) * sizeof(char));
    if(!len)
        exit(EXIT_FAILURE);

    str[0] = '\0';
    int i = 0;
    int j;
    int index = 0;
    int found;
    size_t counter = 0;
    while(text[i])
    {
        if(!check_char(text[i], str))
        {
            i++;
            continue;
        }
        found = 1;
        j = i + 1;
        while(text[j] && found)
        {
            if((text[i] == text[j]) || (convert(text[j]) == text[i]))
            {
                str[index++] = text[i];
                str[index] = '\0';
                counter++;
                found = 0;
            }
            j++;
        }
        i++;
    }
    return counter;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        //indivisibility  
        size_t res = duplicate_count(av[1]);
        printf("%ld\n", res);
    }
    return 0;
}