# include <stdio.h>



// int lengthOfLongestSubstring(char* s)
int longest_unique_substring(char *s)
{
    int seen[128] = {0};
    int i = 0;
    while(i < 128) seen[i++] = -1;
        
    int right = 0;
    int left = 0;
    int max_len = 0;
    while(s[right])
    {
        char st = s[right];

        if(seen[st] >= left)
        {
            left = ++seen[st];
        }
        
        seen[st] = right;
        int len = right - left + 1;
        if(len > max_len)
            max_len = len;
        right++;
    }
    return max_len;
}
int main()
{
    // char *s = "abcabcbb";
    char *s = "aaaaaa";
    printf("%d\n", longest_unique_substring(s));
}