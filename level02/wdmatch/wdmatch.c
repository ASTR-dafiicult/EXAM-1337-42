# include <unistd.h>

int ft_strcmp(char *s1 , char *s2)
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
    return s1[i] - s2[i];
}

int find_it(char R, char *M, int A)
{
    while(M[A])
    {
        if(R == M[A])
        {
            return (A + 1);
        }
        A++;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int j = 0;
        int val = 0;
        char *tab;
        while(av[1][i])
        {
            if(val = find_it(av[1][i], av[2], val))
            {
                tab[j] = av[1][i];
                j++;
            }
            else{
                write(1, "\n", 1);
                return 0;
            }
            i++;
        }
        tab[j] = '\0';
        i = 0;
        if(ft_strcmp(av[1], tab) == 0)
        {
            while(tab[i])
            {
                write(1, &tab[i++], 1);
            }
        }
    }
    write(1, "\n", 1);
}