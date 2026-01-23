# include <unistd.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}
char check_char(char c)
{
    if((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
    {
        return c += 13;
    }
    else if((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
    {
        return c -= 13;
    }
    else
        return 0;
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 0;
        char c;
        while(av[1][i])
        {
            c = check_char(av[1][i]);
            if(c)
            {
                ft_putchar(c);
            }
            else{
                ft_putchar(av[1][i]);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}