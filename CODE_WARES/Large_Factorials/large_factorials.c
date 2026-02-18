#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Compute the exact value of n! and return the result as a string
char  *factorial(int  n) //15511210043330985984000000" | 
{
    if(n < 0)
        return " ";
    int arr[256];
    arr[0] = 1;
    int size = 1;
    int i = 2;
    int rem;
    int prod;
    int j;
    while(i <= n)
    {
        j = 0;
        rem = 0;
        while(j < size)
        {
            prod = arr[j] * i + rem;
            arr[j] = prod % 10;
            rem = prod / 10;
            j++;
        }
        while(rem != 0)
        {
            arr[size++] = rem % 10;
            rem /= 10;
        }
        i++;
    }
    char *str = malloc((size + 1) * sizeof(char));
    if(!str)
        return NULL;
    str[size] = '\0';
    i = size - 1;
    j = 0;
    while(i >= 0)
    {
        str[i--] = arr[j++] + 48;
    }
    return str;
}
int main()
{
    int nb = -1;
    char *arr = factorial(nb);
    printf("%s\n", arr);
    free(arr);
}