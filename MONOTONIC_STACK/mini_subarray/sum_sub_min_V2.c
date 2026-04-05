# include <unistd.h>
# include <stdlib.h>



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
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar((nb % 10) + 48);
}
long long sum_sub_mini(int *res, int size)
{
    int *stack = malloc(size * sizeof(int));
    int *NSE = malloc(size * sizeof(int));
    int *PSE = malloc(size * sizeof(int));
    if(!stack || !NSE || !PSE)
        exit(EXIT_FAILURE);

    int i = 0;
    int j = -1;
    //find previous smaller elements
    while(i < size)
    {
        while(j >= 0 && res[stack[j]] >= res[i])
            j--;

        PSE[i] = (j >= 0) ? stack[j] : -1;
        stack[++j] = i;
        i++;
    }

    //find next small elements
    i = size - 1;
    j = -1;
    while(i >= 0)
    {
        while(j >= 0 && res[stack[j]] > res[i])
            j--;

        NSE[i] = (j >= 0) ? stack[j] : size;
        stack[++j] = i;
        i--;
    }

    //count sum ====> res[i] * (i - PSE[i]) * (NSE[i] - i);
    i = 0;
    long sum = 0;
    while(i < size)
    {
        int LE = i - PSE[i];
        int RE = NSE[i] - i;//large
        sum += res[i] * LE * RE;
        i++;
    }
    free(stack);
    free(NSE);
    free(PSE);
    return sum;
}
int main()
{
    int arr[] = {3, 1, 2, 4};
    ft_putnbr(sum_sub_mini(arr, 4));
    ft_putchar('\n');
}