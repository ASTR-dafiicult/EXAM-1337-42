# include "unistd.h"
# include "stdio.h"


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void print_result(int *combn, int n)
{
    int i = 0;
    while(i < n)
    {
        ft_putchar(combn[i] + 48);
        i++;
    }
    if(combn[0] != 10 - n)
    {
        ft_putchar(',');
        ft_putchar(' ');
    }
}
void generet_combn(int *combn, int n, int index, int val)
{
    if(index == n)
    {
        print_result(combn, n);
    }
    while(val <= 9)
    {
        combn[index] = val;
        generet_combn(combn, n, index + 1, val + 1);
        val++;
    }
}
void ft_print_combn(int nb)
{
    if(nb >= 0 && nb <= 9)
    {
        int combn[9];
        generet_combn(combn, nb, 0, 0);
    }
}
int main()
{
    ft_print_combn(2);
    ft_putchar('\n');
}