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
int check_char(char c, char str)
{
    if(c == str)
    {
        return 1;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 4)
    {
        int i = 0;
        int j = 0;
        int val = 0;
        while(av[1][i])
        {
            if((ft_strlen(av[2]) > 1) || (ft_strlen(av[3]) > 1))
            {
                write(1, "\n", 1);
                return 0;
            }
            val = check_char(av[1][i], av[2][j]);
            if(val)
            {
                write(1, &av[3][j], 1);
            }
            else{
                write(1, &av[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}