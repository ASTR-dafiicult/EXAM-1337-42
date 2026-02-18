# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int intcmp(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}
double mean_square_error(size_t n, const int a[n], const int b[n]) 
{
    int *arr = calloc(n, sizeof(double));
    if(!arr)
        exit(EXIT_FAILURE);
    size_t i = 0;
    int j = 0;
    double res = 0;
    double val = 0;
    while(i < n)
    {
        val = intcmp(a[i], b[i]);
        if(val > b[i])
            res = a[i] - b[i];
        else
            res = b[i] - a[i];
        arr[j++] = pow(res, 2);
        i++; 
    }
    i = 0;
    double sum = 0;
    while(i < n)
    {
        sum += arr[i++];
    }
    return sum / n;
}
int main()
{
    const int arr1[] = {-1, 0};
    const int arr2[] =  {0, -1};
    size_t n = 2;
    printf("%f\n", mean_square_error(n, arr1, arr2));
}