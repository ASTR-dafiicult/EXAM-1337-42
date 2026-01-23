# include "../includes/libcat.h"

int main(int ac, char **av)
{
    if(ac == 1)
    {
        in_to_out();
        return 0;
    }
    int i;
    i = 1;
    while(i < ac)
    {
        ft_cat(av[0], av[i]);
        i++;
    }
    return 0;
}