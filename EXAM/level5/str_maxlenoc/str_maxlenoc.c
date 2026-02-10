# include <unistd.h>
# include <stdlib.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;

    return i;
}
void pustrs(char *str)
{
    int i = 0;
    while(str[i])
        write(1, &str[i++], 1);
}
int check_char(char c, char *av, int index)
{
    int i = index;
    while(av[i])
    {
        if(av[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int check_all(char c, char **av, int ac, int index)
{
    int i = 2;
    while(i < ac)
    {
        if(!check_char(c, av[i], index))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int len = ft_strlen(av[1]);
        char *curr = malloc(len + 1);
        int cur_len = 0;
        int j = 0;
        int i = 0;
        int index = 0;
        while(av[1][i])
        {
            if(check_all(av[1][i], av, ac, index))
            {
                curr[cur_len++] = av[1][i];
                index += 1;
                j++;
            }
            else
                cur_len = 0;
            i++;
        }
        curr[j] = '\0';
        pustrs(curr);
        free(curr);
    }
    write(1, "\n", 1);
    return 0;
}