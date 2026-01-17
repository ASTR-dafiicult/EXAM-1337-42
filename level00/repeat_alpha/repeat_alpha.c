# include <unistd.h>


int main(int ac , char **av)
{
    if(ac == 2)
    {
        int i = 0;
        int repeat;
        while(av[1][i])
        {
            repeat = 0;
            if(av[1][i] >= 97 && av[1][i] <= 122)
            {
                repeat = av[1][i] - 97 + 1;
            }
            else if(av[1][i] >= 65 && av[1][i] <= 90)
            {
                repeat = av[1][i] - 65 + 1;
            }
            else{
                write(1, &av[1][i], 1);
            }
            while(repeat--)
            {
                write(1, &av[1][i], 1);
            }
            i++;
        }   
    }
    write(1, "\n", 1);
}
