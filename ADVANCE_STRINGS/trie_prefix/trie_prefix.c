# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


int check_char(char **str, char c, int index, int size)
{
    int i = 0;
    while(i < size)
    {
        if(str[i][index] == '\0' || str[i][index] != c)
            return 0;
        i++;
    }
    return 1;
}
char *longest_common_prefix(char **strs, int size, int *size_re)
{
    char *res = malloc(256);
    if(!res)
        exit(EXIT_FAILURE);

    int i = 0;
    int j = 0;
    int index = 0;
    while(strs[i][j])
    {
        if(check_char(strs, strs[i][j], j, size))
        {
            res[index++] = strs[i][j];
        }
        else
            break;
        j++;
    }
    res[index]= '\0';
    *size_re = index;
    return res;
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int len = 0;
        char *s = longest_common_prefix(av + 1, ac - 1, &len);
        write(1, s, len);
        free(s);
    }
    write(1, "\n", 1);
}
