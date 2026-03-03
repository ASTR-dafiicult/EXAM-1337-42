# include <unistd.h>
# include <stdio.h>



void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int convert_sum(int nb)
{
    int sum = 0;
    int tmp = nb;
    while(tmp)
    {
        sum += tmp % 10;
        tmp /= 10;
    }
    return sum;
}
void ft_sum_dogits(int nbr)
{
    int sum = convert_sum(nbr);
    ft_putnbr(convert_sum(sum));
    ft_putchar('\n');
}
/*
int main()
{
    int nbr = 1337;
    ft_sum_dogits(nbr);

}
*/
