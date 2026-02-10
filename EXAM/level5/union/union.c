# include <unistd.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}
int check_new_array(char c, char *str)
{
    int i = 0;
    while(str[i])
    {
        if(c == str[i])
            return 0;
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int j = 0;
        char str[56] = {0};
        while(av[1][i])
        {
            if(check_new_array(av[1][i], str))
            {
                str[j] = av[1][i];
                j++;
            }
            i++;
        }
        i = 0;
        while(av[2][i])
        {
            if(check_new_array(av[2][i], str))
            {
                str[j] = av[2][i];
                j++;
            }
            i++;
        }
        str[j] = '\0';
        i = 0;
        while(str[i])
            ft_putchar(str[i++]);
    }
    ft_putchar('\n');
    return 0;
}