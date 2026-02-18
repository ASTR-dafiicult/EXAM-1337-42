#include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void print(char c)
{
    write(1, &c, 1);
}
void putnbr(int nb)
{
    if(nb > 9)
        putnbr(nb / 10);
    print(nb % 10 + 48);
}
void josephus_permutation (size_t n, int permuted[n], const int array[n], size_t k)
{
    int *arr = malloc(n * sizeof(int));
    size_t i = 0;
    while(i < n)
    {
        arr[i] = array[i];
        i++;
    }
    size_t j = 0;
    size_t index = 0;
    size_t nbr = n;
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
        if(i != n)
            print(' ');
    }
    print('\n');

    free(arr);
}
int main()
{
    const int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int array[7];
    josephus_permutation(7, array, arr, 3);
}