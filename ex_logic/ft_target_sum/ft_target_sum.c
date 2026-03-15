# include <unistd.h>
# include <stdlib.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == 0)
        ft_putchar('0');
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + 48);
}
int check(int n1, int n2, int target)
{
    if(n1 + n2 == target)
        return 1;
    else
        return 0;
}
int *copY(int n1, int n2)
{
    int *tab = malloc(2 * sizeof(int));
    tab[0] = n1;
    tab[1] = n2;
    return tab;
}
int **ft_target_sum(int *tab, int size, int target)
{
    int **res = malloc(size * sizeof(int *));
    if(!res)
        exit(EXIT_FAILURE);

    int i = 0;
    int j;
    int index = 0;
    while(i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if(check(tab[i], tab[j], target))
            {
                res[index++] = copY(tab[i], tab[j]);
            }
            j++;
        }
        i++;
    }
    res[index] = NULL;
    return res;
}
int main()
{
    int arr[] = {100, 20, 100, 4, 7, 5, 5};
    int target = 200;
    int **res = ft_target_sum(arr, 7, target);
    int i = 0;
    int j;
    while(res[i] != NULL)
    {
        j = 0;
        while(j < 2)
        {
            ft_putnbr(res[i][j++]);
            ft_putchar(' ');
        }
        free(res[i]);
        ft_putchar('\n');
        i++;
    }
    free(res);
}