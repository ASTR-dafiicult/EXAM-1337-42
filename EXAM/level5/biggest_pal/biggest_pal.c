# include <unistd.h>
# include <stdlib.h>


int check_palindrom(char *new, int *length, int from, int to)
{
    *length = 0;
    int left = from;
    int right = to;
    while(left <= right)
    {
        if(new[left] != new[right])
            return 0;
        left++;
        right--;
    }
    *length = to - from + 1;//len2
    return 1;
}
char *brute_force(char *str, int len)
{
    char *tab = malloc((len + 1) * sizeof(char));
    
    int len2 = 0;
    int len1 = 0;
    int i = 0;
    int index;
    int from;
    int to;
    int j;
    int k;
    while(str[i])
    {
        from = i;
        to = i + 1;
        j = i;
        while(str[j])
        {
            if(check_palindrom(str, &len2, from, to))
            {
                if(len2 >= len1)
                {
                    len1 = len2;
                    k = from;
                    index = 0;
                    while(k <= to)
                    {
                        tab[index++] = str[k++];
                    }
                }
            }
            to++;
            j++;
        }
        i++;
    }
    tab[index] = '\0';
    return tab;
}
//"aaaaaaaaaabbcbbaaaa"
//"aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
char *biggest_pal(char *str, int *size)
{
    int len = 0;
    while(str[len])
        len++;

    *size = len;
    return brute_force(str, len);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int size = 0;
        char *res = biggest_pal(av[1], &size);
        write(1, res, size);
        free(res);
    }
    write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}