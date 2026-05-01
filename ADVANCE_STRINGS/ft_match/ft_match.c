# include <stdio.h>
# include <stdlib.h>


int check_match(char *pat, char c, int index)
{
    while(pat[index])
    {
        if(c == pat[index] || pat[index] == '*')
            return index;
        if(pat[index] == '.')
        {
            return index;
        }
        index++;
    }
    return -1;
}
int  ft_match(char *s, char *pattern)
{

    int i = 0;
    int index = 0;
    int access = 0;
    while(s[i])
    {
        index = check_match(pattern, s[i], index);
        if(index == -1)
        {
            return 0;
        }
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
int main()
{

    printf("(%d)\n", ft_match("abcdaa", ".*"));

    // printf("(%d)\n", ft_match("ab",    ".*"));
    // printf("(%d)\n", ft_match("aab",   "c*a*b"));
    // printf("(%d)\n", ft_match("hello", "h.llo"));
    // printf("(%d)\n", ft_match("aa", "a"));
    printf("(%d)\n", ft_match("aa", ".*c"));

      
}