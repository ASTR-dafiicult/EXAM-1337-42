# include <stdio.h>
# include <unistd.h>


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
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        while(av[1][i])
            i++;

        int size = i - 1;
        int print = 0;
        int first = 1;
        while(av[1][size] && size >= 0)
        {
            while(av[1][size] && !space(av[1][size]))
            {
                size--;
            }
            print = size + 1;
            if(!first)
                ft_putchar(' ');
            while(!space(av[1][print]) && av[1][print])
            {
                ft_putchar(av[1][print++]);
                first = 0;  
            }
            while(av[1][size] && space(av[1][size]))
            {
                size--;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}