# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int check_number(int *res, int nb, int index, int size)
{
    int count = 0;
    int i = index;
    while(i < size)
    {
        if(nb < res[i])
        {
            count++;
            return count;
        }
            count++;
        i++;
    }
    return 0;
}
int *dailyTemperature(int *temperatures, int size, int *returnSize)
{
    int *res = malloc(size * sizeof(int));

    int count;
    int i = 0;
    int index = 0;
    while(i < size)
    {
        count = check_number(temperatures, temperatures[i], i + 1, size);
        res[index++] = count;
        i++;
    }
    *returnSize = index;
    return res;
}
# include <stdio.h>
int main()
{
    int tmp[] = {73,74,75,71,69,72,76,73};//55,38,53,81,61,93,97,32,43,78
    int size = 8;
    int c = 0;
    int *res = dailyTemperature(tmp, size, &c);
    int i = 0;
    while(i < c)
    {
        ft_putnbr(res[i++]);
        if(i != c)
            ft_putchar(' ');
    }
    ft_putchar('\n');
    free(res);
}
//30,60,90
//73,74,75,71,69,72,76,73
//30,40,50,60