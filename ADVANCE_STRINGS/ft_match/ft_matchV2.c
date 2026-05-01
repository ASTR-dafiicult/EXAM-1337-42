int check_match(char *pattern, char c, int index)
{
    int i = index;
    while(pattern[i])
    {
        if(pattern[i] == c || pattern[i] == '*')
            return i;
        if(pattern[i] == '.')
            return i;
        i++;
    }
    return -1;
}
int ft_match(char *str, char *pattern)
{
    int access = 0;
    int i = 0;
    int index = 0;
    while(str[i])
    {
        index = check_match(pattern, str[i], index);
        if(index == -1)
            return 0;
        else
            index++;
        if(pattern[index - 1] == '.')
        {
            access = 1;
        }
        if(access && pattern[index] == '*')
        {
            index--;
            access = 0;
        }
        i++;
    }
    return 1;
}
#include <stdio.h>
int main()
{
    printf("(%d)\n", ft_match("abcdaa", ".*"));
    printf("(%d)\n", ft_match("ab",    ".*"));
    printf("(%d)\n", ft_match("aab",   "."));
    printf("(%d)\n", ft_match("hello", "h.llo"));
    printf("(%d)\n", ft_match("aa", "a"));
    printf("(%d)\n", ft_match("aa", ".*c"));
}