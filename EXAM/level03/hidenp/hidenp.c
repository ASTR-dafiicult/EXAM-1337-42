# include <unistd.h>
# include <stdio.h>

int char_in_order(char c, char *av2, int index)
{
    while(av2[index])
    {
        if(c == av2[index])
        {
            return index;
        }
        index++;
    }
    return 0;
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int index = 0;
        char *tab;
        int j = 0;
        while(av[1][i])
        {
            index = char_in_order(av[1][i], av[2], index);
            if(index)
            {
                tab[j] = av[1][i];
                j++;
            }
            i++;
        }
        if(ft_strcmp(tab, av[1]) == 0)
        {
            write(1, "1\n", 2);
            return 0;
        }
        write(1, "0", 1);
    }
    write(1, "\n", 1);
    return (0);
}