#include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

int gcd(int a, int b)
{
    int rem;
    while(b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int smallest_possible_sum(size_t length, const int array[length]) 
{
    int *arr = malloc(length * sizeof(int));
    if(!arr)
        exit(EXIT_FAILURE);
    size_t i = 0;
    while(i < length)
    {
        arr[i] = array[i];
        i++;
    }
    i = 1;
    int g = arr[0];
    while(i < length)
    {
        g = gcd(g, arr[i]);
        i++;
    }
    return g * length;
}
int main()
{
    const int arr[] = {6, 9, 21};
    printf("%d\n", smallest_possible_sum(3, arr));
}