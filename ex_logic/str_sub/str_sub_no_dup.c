# include <stdio.h>

int lengthOfLongestSubstring(char* s)
{   
    int size = 0;
    int max = 0;
    int access;
    int i = 0;
    int k;
    while(s[i])
    {
        size = 1;
        access = 1;
        int j = i + 1;
        while(s[j] && access)
        {
        
            k = i;
            while(s[k] && k < j)
            {
                if(s[j] == s[k])
                {
                    access = 0;
                    break;
                }
                k++;
            }
            if(access)
                size++;
            j++;
        }
        if(max < size)
            max = size;
        i++;
    }
    return max;
}
int main()
{
    char *s1 = "pwwkew";
    char *s2 = "abcabcbb";
    char *s3 = "bbbbbbbbbb";
    char *s4 = "dvdf";
    int len1 = lengthOfLongestSubstring(s1);
    printf("%d\n", len1);
    int len2 = lengthOfLongestSubstring(s2);
    printf("%d\n", len2);
    int len3 = lengthOfLongestSubstring(s3);
    printf("%d\n", len3);
    int len4 = lengthOfLongestSubstring(s4);
    printf("%d\n", len4);
}