# include <unistd.h>

int char_in_order(char c, char *av2, int index)
{
    while(av2[index])
    {
        if(c == av2[index])
        {
            return index + 1;
        }
        index++;
    }
    return -1;
}
int main(int ac, char **av)
{
    if(ac == 3)
    {
        int i = 0;
        int j = 0;
        int acc = 1;
        int index = 0;
        
        while(av[1][i] && acc)
        {
            index = char_in_order(av[1][i], av[2], index);
            if(index == -1)
            {
                acc = 0;
            }
            i++;
        }
        if(acc)
            write(1, "1\n", 2);
        else
            write(1, "0\n", 2);

        return 0;
    }
    write(1, "\n", 1);
    return (0);
}