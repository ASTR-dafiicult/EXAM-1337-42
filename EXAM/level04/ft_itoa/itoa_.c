# include <stdlib.h>


char    *ft_itoa(int nbr)
{

    int nb;
    int tmp;
    int i;
    int size;
    char *tab;

    nb = nbr;
    if(nb < 0)
    {
        nb *= -1;
        size = 1;
    }
    tmp = nb;
    while(tmp)
    {
        tmp /= 10;
        size++;
    }
    tab = malloc(size + 1);
    if(!tab)
    return NULL;
    
    if(nbr == 0)
    {
        tab[0] = '0';
        tab[1] = '\0';
        return tab;
    }
    i = size - 1;
    tab[size] = '\0';
    while(nb)
    {
        tab[i--] = (nb % 10) + 48;
        nb /= 10;
        if(nbr < 0)
        {
            tab[0] = '-';
            nbr = nb;
        }
    }
    return tab;
}
/*
# include <stdio.h>
int main()
{
    int nbr = 120212312;
    int nbr2 = 0;
    char *str = ft_itoa(nbr);
    printf("%s\n", str);
}
*/