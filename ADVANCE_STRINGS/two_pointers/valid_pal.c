# include <stdio.h>



int check_pal(char *s, int left, int right)
{
    while(left < right)
    {
        if(s[left] != s[right])
            return 0;
        left++;
        right--;
    }
    return 1;
}
int valid_palindrom(char *s)
{
    if(!s)
        return 0;

    int len = 0;
    while(s[len])
        len++;

    int right = len - 1;
    int left = 0;
    int val;
    while(left < right)
    {
        if(check_pal(s, left + 1, right) || check_pal(s, left, right - 1))
            return 1;
        left++;
        right--;
    }
    return 0;
}
int main()
{
    char *s = "abc";
    printf("%d\n", valid_palindrom(s));
}