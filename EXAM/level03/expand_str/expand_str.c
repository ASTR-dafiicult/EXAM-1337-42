# include <unistd.h>


void    ft_putchar(char c)
{
    write(1, &c, 1);
}
int      check_space(char c)
{
    if(c == 32 || c == 9)
    {
        return 1;
    }
    return 0;
}
void expande_str(char *str)
{
    int j;
    int i = 0;
    int len = 0;
    int last = 1;

    while(str[len])
        len++;

    while(str[len - 1] == 32 || str[len - 1] == 9)
    {
        len--;
    }
    while(str[i] == 32 || str[i] == 9)
    {
        i++;
    }
    while(str[i] && i < len)
    {
        j = 0;
        while(check_space(str[i]) && last)
        {
            ft_putchar(32);
            j++;
            if(j == 3)
            {
                last = 0;
            }
        }
        if(!check_space(str[i]))
        {
            ft_putchar(str[i]);
            last = 1;
        }
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        expande_str(av[1]);
    }
    write(1, "\n", 1);
}