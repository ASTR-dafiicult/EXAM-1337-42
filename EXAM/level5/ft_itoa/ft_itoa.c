# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_itoa(int nbr)
{
    int size = 0;
    int nb = nbr;
    if(nb < 0)
    {
        nb *= -1;
        size = 1;
    }
    int tmp = nb;
    while(tmp)
    {
        tmp /= 10;
        size++;
    }
    char *str = malloc(size + 1);
    if(!str)
        return NULL;
    if(nbr == 0)
    {
        str = malloc(2);
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if(nbr < 0)
    {
        str[0] = '-';
    }
    str[size] = '\0';
    int i = size - 1;
    while(nb)
    {
        str[i--] = (nb % 10) + 48;
        nb /= 10;
    }
    return str;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int nb = atoi(av[1]);
        char *str = ft_itoa(nb);
        printf("%s\n", str);
    }
}