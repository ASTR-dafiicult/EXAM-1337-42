#include <stdlib.h>

double *multiples(int m, double n) 
{
    double *arr = malloc(m * (sizeof(double)));
    int i = 1;
    int j = 0;
    while(i <= m)
    {
        arr[j++] = i++ * n;
    }
    return arr;
}
/*
# include <stdio.h>
int main()
{
    int i = 0;
    double *arr = multiples(10, 2);
    while(i < 10)
    {
        printf("%d   ", (int)arr[i++]);
    }
    free(arr);
    printf("\n");
}
*/