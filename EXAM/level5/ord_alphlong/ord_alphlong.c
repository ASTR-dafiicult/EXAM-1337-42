# include "alphlong.h"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        char **tab = split(av[1]);
        int i = 0;
        int j;
        while(tab[i])
        {
            j = i + 1;
            while(tab[j])
            {
                if(sort_length(tab[i], tab[j]))
                    swap(&tab[i], &tab[j]);
                if(ft_strlen(tab[i]) == ft_strlen(tab[j]))
                    if(ord_alphlong(tab[i], tab[j]) > 0)
                        swap(&tab[i], &tab[j]);
                j++;
            }
            i++;
        }
        i = 0;
        while(tab[i])
        {
            ft_putstr(tab[i]);
            if(tab[i + 1] && ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
                write(1, " ", 1);
            else
                write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return 0;
}

// another main function
/*
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char **res = split(av[1]);
        int j;
        int i = 0;
        while(res[i])
        {
            j = i + 1;
            while(res[j])
            {
                if(sort_length(res[i], res[j]))
                    swap(&res[i], &res[j]);
                j++;
            }
            i++;
        }
        //sort by alpha
        //printing
        i = 0;
        while(res[i])
        {
            int len_i = ft_strlen(res[i]);
            j = i + 1;
            while(res[j])
            {
                int len_j = ft_strlen(res[j]);
                if(len_i == len_j)
                {
                    if(ord_alphlong(res[i], res[j]) > 0)
                        swap(&res[i], &res[j]);
                }
                j++;
            }
            i++;
        }
        i = 0;
        while(res[i])
        {
            ft_putstr(res[i]);
            if(res[i + 1] && ft_strlen(res[i]) == ft_strlen(res[i + 1]))
                write(1, " ", 1);
            else
                write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return 0;
}
*/