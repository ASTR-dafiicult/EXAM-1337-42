# include <unistd.h>
 
int main(int ac, char **av)
{
    if(ac == 1)
    {
        write(1, "z\n", 2);
        return 0;
    }
    int i = 1;
    int j;
    while(ac > i)
    {
        j = 0;
        while(av[i][j])
        {
            if(av[i][j] == 'z')
            {
                write(1, "z\n", 2);
                return 0;
            }
            j++;
        }
        if(i == ac - 1)
        {
            write(1, "z\n", 2);
        }
        i++;
    }
}

/*
int		main(void)
{
	write(1, "z", 1);
	write(1, "\n", 1);
	return (0);
}
*/