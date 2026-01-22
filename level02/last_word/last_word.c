# include <unistd.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int blank(char c)
{
    if(c == 32 || c == 9)
    {
        return 1;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = (ft_strlen(av[1]) - 1);
        while(blank(av[1][i]))
            i--;
        while(!blank(av[1][i]))
            i--;
        i++;
        while(av[1][i] && !blank(av[1][i]))
        {
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
