# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
char convert_char(char c)
{
    char s;
    if(c >= 65 && c <= 90)
    {
        s = 90 - (c - 65);
        return s;
    }
    else if(c >= 97 && c <= 122)
    {
        s = 122 - (c - 97);
        return s;
    }
    else
        return 0;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        while(av[1][i])
        {
            if((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
                ft_putchar(convert_char(av[1][i]));
            else
                ft_putchar(av[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}