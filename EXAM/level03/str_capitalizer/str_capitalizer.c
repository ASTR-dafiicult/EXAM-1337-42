# include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void str_capitalizer(char *str)
{
    int i = 0;
    int first = 1;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z' && !first)
        {
            str[i] += 32;
        }
        if(((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && first)
        {
            if(str[i] >= 97 && str[i] <= 122)
                str[i] -= 32;

            ft_putchar(str[i]);
            first = 0;
        }
        else
            ft_putchar(str[i]);
        if(str[i] == 32 || str[i] == 9)
            first = 1;
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 1;
        while(av[i])
        {
            str_capitalizer(av[i]);
            ft_putchar('\n');
            i++;
        }
        return 0;
    }
    ft_putchar('\n');
}