# include <unistd.h>


int check_char(char s, char *av2)
{
    int i = 0;
    while(av2[i])
    {
         if(av2[i] == s)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int see_it_bef(char c, char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int j = 0;
        int yes = 0;
        char see[100] = {0};
        while(av[1][i])
        {
            if(check_char(av[1][i], av[2]))
                yes = 1;
            else
                yes = 0;
            if(yes && !see_it_bef(av[1][i], see))
            {
                write(1, &av[1][i], 1);
                see[j] = av[1][i];
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}