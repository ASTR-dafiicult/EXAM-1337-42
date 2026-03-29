# include <unistd.h>
# include <stdlib.h>


int check_palindrom(char *str, int *length, int from, int to)
{
    int start = from;
    int end = to;
    *length = 0;
    while(start <= end)
    {
        if(str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    *length = to - from + 1;
    return 1;
}
int get_type(char *str, int left, int right, int size)
{
    while(left >= 0 && right < size && str[left] == str[right])
    {
        left--;
        right++;
    }
    return (right - left) - 1;
}
char *center_brute(char *str, int *size)
{
    char *res = malloc((*size + 1) * sizeof(char));
    if(!res)
        exit(EXIT_FAILURE);
    int access = 0;
    int index = 0;
    int right = 0;
    int left = 0;
    int len1 = 0;
    int len2 = 0;
    int i = 0;
    while(str[i])
    {
        int odd = get_type(str, i, i, *size);
        int even = get_type(str, i, i + 1, *size);
        if(odd >= even)
        {
            left = i;
            right = i;
        }
        else
        {
            left = i;
            right = i + 1;
        }
        while(right < *size && left >= 0 && str[left] == str[right])//boob
        {
            if(i != 0)
            {
                right++;
                left--;
            }
            else
                right++;
            if(right == *size || left < 0 || str[left] != str[right])
            {
                check_palindrom(str, &len1, left + 1, right - 1);
                access = 1;
            }
        }
        if(access)
        {
            if(len1 >= len2)
            {
                len2 = len1;
                index = 0;
                while(index < len1)
                {
                    res[index++] = str[++left];
                }
            }
            access = 0;
        }
        i++;
    }
    res[index] = '\0';
    *size = index;
    return res;
}
char *biggest_pal(char *str, int *len)
{
    int size = 0;
    while(str[size])
        size++;
    
    char *res = center_brute(str, &size);
    *len = size;
    return res;
}
# include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 2)
    {

        int len = 0;
        char *res = biggest_pal(av[1], &len);
        write(1, res, len), free(res);
    }
    write(1, "\n", 1);
}