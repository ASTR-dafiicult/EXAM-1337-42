# include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
int count_char(char c, char *str)
{
    int i = 0;
    int con = 0;
    while(str[i])
    {
        if(c == str[i])
            con++;
        i++;
    }
    return con;
}

int ft_is_base_anagram(char *s1, char *s2, char *base)
{
    int s1_len = ft_strlen(s1);
    int s2_len = ft_strlen(s2);
    if(s1_len != s2_len)
        return 0;
    int i = 0;
    int j = 0;
    while(base[j])
    {
        int val1 = count_char(base[j], s1);
        int val2 = count_char(base[j], s2);
        if(val1 != val2)
            return 0;
        j++;
    }
    return 1;
}
int main()
{
    char *base = "abc";
    char *s1 = "abbcc";
    char *s2 = "aabcc";
    int val = ft_is_base_anagram(s1, s2, base);
    if(val)
        printf("true\n");
    else
        printf("false\n");
}