# include <unistd.h>
# include <stdlib.h>


int check_char_res(char c, char *res)
{
    int i = 0;
    while(res[i])
    {
        if(c == res[i])
            return 0;
        i++;
    }
    return 1;
}
int len_of(int nb)
{
    int size = 0;
    while(nb)
    {
        nb /= 10;
        size++;
    }
    return size;
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
char *ft_compress_str(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    char *res = malloc((i + 1) * sizeof(char));
        if(!res)
            exit(EXIT_FAILURE);
    i = 0;
    int index = 0;
    res[index] = '\0';
    while(str[i])
    {
        int val = count_char(str[i], str);

        if(!check_char_res(str[i], res))
        {
            i += val;
            continue;
        }
        if(val > 9)
        {
            res[index++] = str[i];
            int len = len_of(val);
            int j = (len - 1) + index;
            int nb = val;
            while(nb)
            {
                res[j--] = nb % 10 + 48;
                nb /= 10;
            }
            index += len;
            res[index] = '\0';
        }
        else if(val <= 9)
        {
            res[index++] = str[i];
            res[index++] = val + 48;
            res[index] = '\0';
        }
        i += val;
    }
    res[index] = '\0';
    return res;
}
# include <stdio.h>
int main()
{
    char *res = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaavvaaaaaaaaabbbbbccccccccccckkkkbkkkkkkaaaaaaaaaaa";
    char *str = ft_compress_str(res);
    printf("%s\n", str);
    free(str);
}