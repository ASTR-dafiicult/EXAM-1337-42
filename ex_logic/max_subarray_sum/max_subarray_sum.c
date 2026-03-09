# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int maxSequence(const int array[/* n */], size_t n)
{
    int *arr = malloc(n * sizeof(int));
    int sum = 0;
    size_t i = 0;
    int j = 0;
    while(i < n)
    {
        sum += array[i++];
        if(sum < 0)
            sum = 0;
        else
            arr[j++] = sum;
    }
    sum = arr[0];
    i = 1;
    while(i <= j)
    {
        if(sum < arr[i])
            sum = arr[i];
        i++;
    }
    free(arr);
    return sum;
}
int main()
{
    const int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = maxSequence(arr, 8);
    printf("%d\n", n);
}
