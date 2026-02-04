# include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] || s2[i])
    {
        if(s1[i] != s2[i])
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
int check_char(char c, char *av2, int index)
{
    while(av2[index])
    {
        if(av2[index] == c)
            return index;
        index++;
    }
    return -1;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int j = 0;
        char tab[256] = {0};
        int index = 0;
        int acc = 1;
        while(av[1][i] && acc)
        {
            index = check_char(av[1][i], av[2], index);
            if(index != -1)
            {
                tab[j] = av[1][i];
                j++;
            }
            else
                acc = 0;
            i++;
        }
        tab[j] = '\0';
        if(ft_strcmp(av[1], tab) == 0)
        {
            write(1, "1\n", 2);
        }
        else
            write(1, "0\n", 2);
        return 0;
    }
    write(1, "\n", 1);
}
