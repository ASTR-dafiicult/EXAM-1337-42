// # include <stdlib.h>

// ---------------------------O(n^3)-----------------------------
// int check_char(char *str, char c)
// {
//     int i = 0;
//     while(str[i])
//     {
//         if(str[i] == c)
//             return 0;
//         i++;
//     }
//     return 1;
// }
// int longest_unique_substring(char *s)
// {
//     int len = 0;
//     while(s[len]) len++;
//     char *seen = malloc((len + 1) * sizeof(char));
//     if(!seen)
//         exit(EXIT_FAILURE);
    
//     int max = 0;
//     int test_len = 0;
//     int i = 0;
//     int index = 0;
//     int j;
//     while(s[i])
//     {
//         index = 0;
//         seen[0] = '\0';
//         test_len = 0;
//         j = i;
//         while(s[j] && check_char(seen, s[j]))
//         {
//             test_len++;
//             seen[index++] = s[j];
//             seen[index] = '\0';
//             j++;
//         }
//         if(test_len > max)
//         {
//             max = test_len;
//         }
//         i++;
//     }
//     free(seen);
//     return max;
// }
// -------------------------O(n)-------------------------------------

int sliding(char *s)
{
    int max = 0;
    int arr[128];
    int i = 0;
    while(i < 128) arr[i++] = -1;
    int right = 0;
    int left = -1;
    while(s[right])
    {
        char c = s[right];
        if(arr[c] >= left)
        {
            left = arr[c] + 1;
        }

        arr[c] = right;
        int len = right - left + 1;
        if(len > max)
            max = len;
        right++;
    }
    return max;
}

# include <stdio.h>
int main()
{
    // char *s = "abcabcbb";
    char *s = "pwwkew";
    // char *s = "bbbbb";
    printf("%d\n", sliding(s));
}
