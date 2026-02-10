# include <unistd.h>
# include <stdlib.h>

void ft_putchar(char c)
{
    write(1, &c, 1);

}
void print_val(int nb)
{
    if(nb == 0)
    {
        ft_putchar('0');
        return;
    }
    if(nb > 9)
        print_val(nb / 10);

    ft_putchar(nb % 10 + 48);
}
int check_prime(int nb)
{
    if(nb <= 1)
        return 0;
    int i = 2;
    while(i <= nb / 2)
    {
        if(nb % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int val = atoi(av[1]);
        int sum = 0;
        int i = 2;
        while(i <= val)
        {
            if(check_prime(i))
            {
                sum += i;
            }
            i++;
        }
        print_val(sum);
    }
    else{
        write(1, "0\n", 2);
        exit(EXIT_FAILURE);
    }
    write(1, "\n", 1);
    exit(EXIT_SUCCESS);
}