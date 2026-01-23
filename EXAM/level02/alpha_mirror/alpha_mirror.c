# include <unistd.h>
# include <stdio.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
int check_alpha(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}
int alpha_mirror(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return 122 - (c - 97);
    }
    if(c >= 'A' && c <= 'Z')
    {
        return 90 - (c - 65);
    }
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int i = 0;
        char val;
        while(av[1][i])
        {
            if(check_alpha(av[1][i]))
            {
                ft_putchar(alpha_mirror(av[1][i]));
            }
            else
            {
                ft_putchar(av[1][i]);
            }
            i++;
        }
    }   
    write(1, "\n", 1);
}