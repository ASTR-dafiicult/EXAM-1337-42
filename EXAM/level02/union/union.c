# include <unistd.h>


int check_av1(char c, char *str)
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
        int j = 0;
        int i = 0;
        char see[30] = {0};
        while(av[1][i])
        {
            if(!check_av1(av[1][i], see))
            {
                see[j] = av[1][i];
                j++;
            }
            i++;
        }
        i = 0; 
        while(av[2][i])
        {
            if(!check_av1(av[2][i], see))
            {
                see[j] = av[2][i];
                j++;
            }
            i++;
        }
        int index = 0;
        while(see[index])
        {
            write(1, &see[index], 1);
            index++;
        }
    }
    write(1, "\n", 1);
}