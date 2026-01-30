# include <stdlib.h>
# include <unistd.h>


char	*ft_itoa(int nbr)
{
    long nb;
    int i;
    int length = 0;
    long tmp;
    char *str;

    nb = nbr;
    if(nb < 0)
    {
        nb *= -1;
    }
    tmp = nb;
    while(tmp)
    {
        tmp /= 10;
        length++;
    }
    str = malloc((length + 1) * sizeof(char));
    if(!str)
        return NULL;
    
    if(nb == 0)
    {
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    if(nbr < 0)
        i = length;
    else
        i = length - 1;
    str[length] = '\0';
    while(nb)
    {
        str[i--] = (nb % 10) + 48;
        nb /= 10;
    }
    if(nbr < 0)
        str[0] = '-';
    return str;
}
/*
int main()
{
    int nbr = -2147483647;
    char *str = ft_itoa(nbr);
    printf("%s\n", str);
    free(str);

}
*/
