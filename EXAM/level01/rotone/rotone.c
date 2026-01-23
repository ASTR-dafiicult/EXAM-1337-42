# include <unistd.h>

int roton(char c)
{
    if((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
    {
        return (c += 1);
    }
    if(c == 'z' || c == 'Z')
    {
        return (c -= 25);
    }
    return 0;
}
int main(int ac , char **av)
{
    if(ac == 2)
    {
        int i = 0;
        char c;
        while(av[1][i])
        {
            c = roton(av[1][i]);
            if(c)
            {
                write(1, &c, 1);
            }
            else{
                write(1, &av[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}