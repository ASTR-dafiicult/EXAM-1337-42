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
void ft_print_str(char *str, int from, int to)
{
    while(str[from] && from <= to)
    {
        ft_putchar(str[from++]);
    }
}
void print_reverse(char *str, int to)
{
    while(str[to] && to >= 0 && !space(str[to]))
    {
        ft_putchar(str[to--]);
    }
}
void ft_print_zig_zag(char *str)
{
    int i = 0;
    int from;
    int to;
    int sp = 1;
    int access = 1;
    while(str[i])
    {
        while(space(str[i]) && str[i])
            i++;
        if(!sp && str[i])
        {
            ft_putchar(' ');
            sp = 1;
        }
        from = i;
        while(str[i] && !space(str[i]))
        {
            i++;
        }
        to = i - 1;
        if(access)
        {
            ft_print_str(str, from, to);
            access = 0;
            sp = 0;
        }
        else
        {
            print_reverse(str, to);
            access = 1;
            sp = 0;
        }
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        ft_print_zig_zag(av[1]);
    }
    ft_putchar('\n');
    return 0;
}