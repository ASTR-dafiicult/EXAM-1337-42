# include "unistd.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}
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
    return 0;
}
void ft_swap(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}
char *ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    ft_putchar('\n');
    return str;
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        int j;
        while(i < ac - 1)
        {
            j = 1;
            while(j < ac - i)   // cb aa
            {
                if(ft_strcmp(av[j], av[j + 1]) > 0)
                {
                    ft_swap(&av[j], &av[j + 1]);
                }
                j++;
            }
            i++;
        }
        j = 1;
        while(j < ac)
        {
            ft_putstr(av[j]);
            j++;
        }
    }
    return 0;
}