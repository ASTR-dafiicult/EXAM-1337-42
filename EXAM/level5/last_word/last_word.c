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
        int len = 0;
        int access = 1;
        while(av[1][len])
            len++;

        --len;
        while(access && av[1][len])
        {
            while(av[1][len] && space(av[1][len]))
                len--;
            while(av[1][len] && !space(av[1][len]))
                len--;
            ++len;
            while(av[1][len] && !space(av[1][len]))
            {
                ft_putchar(av[1][len++]);
                access = 0;
            }
        }
    }
    ft_putchar('\n');
    return 0;
}