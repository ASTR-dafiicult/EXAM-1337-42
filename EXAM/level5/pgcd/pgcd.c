# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
int ft_atoi(char *av)
{
    int i = 0;
    int res = 0;
    while(av[i] == 32 || av[i] == 9)
        i++;
    while(av[i] >= '0' && av[i] <= '9')
    {
        res = res * 10 + av[i] - 48;
        i++;
    }
    return res;
}
void print_val(int nb)
{
    if(nb == 0)
    {
        write(1, "0", 1);
        return;
    }
    if(nb > 9)
        print_val(nb / 10);
    ft_putchar(nb % 10 + 48);
}
int pgcd(int n1, int n2)
{
    if(n1 == n2)
        return n1;

    int rem = 0;
    while((rem = n1 % n2) != 0)
    {
        n1 = n2;
        n2 = rem;
    }
    return n2;
}
int main(int argc, char **argv)
{
    if(argc == 3)
    {
        int n1 = ft_atoi(argv[1]);
        int n2 = ft_atoi(argv[2]);

        if(n1 < 0 || n2 < 0)
        {
            write(1, "0\n", 2);
            exit(EXIT_FAILURE);
        }
        print_val(pgcd(n1, n2));
        ft_putchar('\n');
        exit(EXIT_SUCCESS);
    }
    else{
        ft_putchar('\n');
        exit(EXIT_FAILURE);
    }

}