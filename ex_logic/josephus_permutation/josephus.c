# include <unistd.h>
# include <stdlib.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}
void putnbr(int nb)
{
    if(nb > 9)
        putnbr(nb / 10);
    ft_putchar(nb % 10 + 48);
}
void josephus_permutation (size_t n, int permuted[n], const int array[n], size_t k)
{
    int *arr = malloc(n * sizeof(int));
    if(!arr)
        return;
    size_t i = 0;
    while(i < n)
    {
        arr[i] = array[i];
        i++;
    }
    
    i = 0;    
    size_t j = 0;
    size_t nbr = n;
    size_t index = 0;
    while(n)
    {
        index = (index + k - 1) % n;
        permuted[j++] = arr[index];
        i = index;
        while(i < n - 1)
        {
            arr[i] = arr[i + 1];
            i++;
        }
        n--;
        if(index == n)
            index = 0;
    }
    i = 0;
    while(i < nbr)
    {
        putnbr(permuted[i++]);
        if(i != nbr)
            ft_putchar(' ');
    }
    ft_putchar('\n');
}
# include <stdio.h>

int main()
{
    printf("1234567\n");
    const int array[] = {1, 2, 3, 4, 5, 6, 7};
    int arr[7];
    josephus_permutation(7, arr, array, 3);
}