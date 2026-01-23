# include <unistd.h> 

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        int repeat = 0;
        while(av[1][i])
        {
            if(av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                repeat = (av[1][i] - 'a') + 1;
            }
            else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                repeat = (av[1][i] - 'A') + 1;
            }
            else{
                write(1, &av[1][i], 1);
            }
            while(repeat)
            {
                write(1, &av[1][i], 1);
                repeat--;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}