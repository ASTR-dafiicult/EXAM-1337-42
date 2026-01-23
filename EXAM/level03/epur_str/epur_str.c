# include <unistd.h>
# include <stdio.h>


int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
int check_space(char c)
{
    if(c == 32 || c == 9)
    {
        return 0;
    }
    return 1;
}
void epure(char *str)
{
    int i = 0;
    int len = (ft_strlen(str) - 1);
    int first = 1;
    while(!check_space(str[len]))
    {
        --len;
    }
    while(!check_space(str[i]))
    {
        i++;
    }
    while(str[i] && i <= len)
    {
        if(check_space(str[i]))
        {
            write(1, &str[i], 1);
        }
        if((!check_space(str[i])) && (check_space(str[i - 1])))
        {
            write(1, &str[i], 1);
        }
        i++;
    }
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        epure(av[1]);
    }
    write(1, "\n", 1);
}
