# include <unistd.h>


int find_it(char c, char *str, int index)
{
    int i = index;
    while(str[i])
    {
        if(c == str[i])
            return i;
        i++;
    }
    return -1;
}
int main(int ac, char *av[])
{
    if(ac == 3)
    {
        int i = 0;
        int index = 0;
        while(av[1][i])
        {
            index  = find_it(av[1][i] , av[2], index);
            if(index == -1)
            {
                write(1, "0\n", 2);
                return 0;
            }
            i++;
        }
        write(1, "1", 1);
    }
    write(1, "\n", 1);
    return 0;
}
