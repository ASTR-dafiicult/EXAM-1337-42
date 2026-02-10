#include <stdlib.h>

int check_char(char c,const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i])
    {
        if(s1[i++] == c)
            return 1;
    }
    i = 0;
    while(s2[i])
    {
        if(s2[i++] == c)
            return 1;
    }
    return 0;
}
char *longest (const char *s1, const char *s2)
{
    char *str = malloc((26 + 1) * sizeof(char)); //allocate max size of alpha
    if(!str)
        exit(EXIT_FAILURE);
    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    int j = 0;
    while(alpha[i])//check char by char from alpha
    {
        if(check_char(alpha[i], s1, s2))//If the letter is present in s1 or s2, return the value 1 and store it in str
            str[j++] = alpha[i];
        i++;    
    }
    str[j] = '\0';
    return str;
}
# include <stdio.h>
int main()
{
    const char *s1 = "vvvvuuuuuuoooooooooooubbbbbbbbvvvqq";
    const char *s2 = "sssssssllllllooooxxxxxxxqqqpppppppppppx";
    char *res = longest(s1, s2);
    printf("%s\n", res);
    free(res);
}