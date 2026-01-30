# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int space(char c)
{
    if(c == 32 || c == 9)
        return 1;
    return 0;
}
void ft_putstr(char *str)
{
    int i = 0;
    while(str[i] && !space(str[i]))
        ft_putchar(str[i++]);
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int size;
        int i = 0;
        int j = 0;
        while(av[1][i] && space(av[1][i]))
        {    
            i++;
        }       
        char *str = &av[1][i];
        while(av[1][i] && !space(av[1][i]))
            i++;
        while(av[1][i]) /// print after get &first char
        {
            while(space(av[1][i]))
                i++;
            while(!space(av[1][i]) && av[1][i])
            {
                ft_putchar(av[1][i]);
                i++;
                if(space(av[1][i]))
                    ft_putchar(' ');
            }
        }
        ft_putchar(' ');
        ft_putstr(str);
    }
    ft_putchar('\n');
    return 0;
}