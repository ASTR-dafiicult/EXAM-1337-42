# include "ft_str_to_tab.h"
# include "stdlib.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
char *ft_strdup(char *str)
{
    char *copy = malloc(ft_strlen(str) + 1);
    if(!copy)
    {
        //copy[0] = '\0';
        //return copy;
        return NULL;
    }
    int i = 0;
    while(str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *tab;
    tab = malloc(sizeof(t_stock_str) * (ac + 1)); // struct extra
    if(!tab)
    {
        return NULL;
    }
    int i = 0;
    while(i < ac)
    {
        tab[i].str = av[i];
        tab[i].copy = ft_strdup(av[i]);
        tab[i].size = ft_strlen(av[i]);
        i++;
    }
    tab[i].str = NULL;

    return tab;
}