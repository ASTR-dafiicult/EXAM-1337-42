# include <stdlib.h>
# include <unistd.h>


int maxSequence(const int array[/* n */], size_t n)
{
    if(!n)
        return 0;
    
    size_t d = 0;
    size_t neg = 0;
    while(d < n)
    {
        if(array[d++] < 0)
            neg++;
    }
    if(neg == n)
    return 0;
        
    int sum = 0;
    size_t i = 0;
    size_t j = 0;
    int *arr = malloc(n * sizeof(int));
    if(!arr)
        exit(EXIT_FAILURE);
    
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
    while(i < j)
    {
        if(arr[i] > sum)
        sum = arr[i];
        i++;
    }
    return sum;
}

# include <stdio.h>
int main()
{
    int arr[] = { 7, 4, 11, -11, 39, 36 , -6};
    int res = maxSequence(arr, 7);
    printf("%d\n", res); // 86 total subarray sum
}